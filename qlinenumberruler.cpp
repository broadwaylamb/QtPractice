//
//  qrulermarker.h
//  QLineNumberRuler
//
//  Created by Sergej Jaskiewicz on 10.12.16.
//
//

#include "qlinenumberruler.h"
#include "qrulermarker.h"
#include "qcodeedit.h"
#include <QPainter>
#include <QPaintEvent>
#include <QVector>
#include <QTextBlock>
#include <QTextCursor>
#include <QTextDocument>

#define RULER_THICKNESS 16

// TODO: Implement accessory widget

QLineNumberRuler::QLineNumberRuler(QCodeEdit *aCodeEdit) : QWidget(aCodeEdit) {
    
    printf("QLineNumberRuler initialized\n");
    _codeEdit = aCodeEdit;
    _ruleThickness = RULER_THICKNESS;
    _reservedThicknessForMarkers = 0.0;
    _reservedThicknessForAccessoryWidget = 0.0;
    _markers = new QVector<QRulerMarker*>(0);
}

void QLineNumberRuler::setAccessoryWidget(QWidget *aWidget) {
    // TODO: support for accessory widgets is not implemented
    _accessoryWidget = aWidget;
    update();
}

QWidget* QLineNumberRuler::accessoryWidget() const {
    return _accessoryWidget;
}

void QLineNumberRuler::_verifyReservedThicknessForMarkers() {
    
    QRulerMarker *marker;
    qreal maxThickness = _reservedThicknessForMarkers;
    
    if (_markers == nullptr) {
        return;
    }
    
    for (auto iterator = _markers->begin(); iterator != _markers->end(); ++iterator) {
        marker = *iterator;
        qreal markerThickness = marker->thicknessRequiredInRuler();
        if (markerThickness > maxThickness) {
            maxThickness = markerThickness;
        }
    }
    
    if (maxThickness > _reservedThicknessForMarkers) {
        setReservedThicknessForMarkers(maxThickness);
    }
}

void QLineNumberRuler::setMarkers(QVector<QRulerMarker*>* newMarkers) {
    _markers = newMarkers;
    update();
}

void QLineNumberRuler::addMarker(QRulerMarker *aMarker) {

    qreal markerThickness = aMarker->thicknessRequiredInRuler();
    
    if (markerThickness > reservedThicknessForMarkers()) {
        setReservedThicknessForMarkers(markerThickness);
    }
    
    if (_markers == nullptr) {
        _markers = new QVector<QRulerMarker*>(1, aMarker);
    } else {
        _markers->push_back(aMarker);
    }
    
    update();
}

void QLineNumberRuler::removeMarker(QRulerMarker *aMarker) {
    if (_markers == nullptr) {
        return;
    }
    
    _markers->removeOne(aMarker);
    
    update();
}

bool QLineNumberRuler::trackMarker(QRulerMarker *aMarker, QMouseEvent *theEvent) {
    if (aMarker == nullptr) {
        return false;
    }
    
    return aMarker->trackMouse(theEvent, true);
}

QCodeEdit* QLineNumberRuler::codeEdit() const {
    return _codeEdit;
}

void QLineNumberRuler::setCodeEdit(QCodeEdit *aCodeEdit) {
    _codeEdit = aCodeEdit;
}

QVector<QRulerMarker*>* QLineNumberRuler::markers() const {
    return _markers;
}

inline static QTextCursor firstVisibleGlyphCursor(QTextEdit *textEdit) {
    return textEdit->cursorForPosition(QPoint(0, 0));
}

inline static void drawLineNumber(int lineNumber, int y, QPainter &painter) {
    
    auto lineNumberString = QString::number(lineNumber);
    QPoint point(0, y);
    painter.drawText(point, lineNumberString);
}

// MARK: Unimplemented
void QLineNumberRuler::drawLineNumbersInRect(QRectF aRect) {
    Q_UNUSED(aRect)
    QPainter painter(this);
    auto cursor = firstVisibleGlyphCursor(_codeEdit);
    auto firstVisibleBlock = cursor.block();
    
    for (auto block = firstVisibleBlock; block.isValid() && block.isVisible(); block = block.next()) {
        
        int lineNumber = block.blockNumber() + 1;
        int y = _codeEdit->cursorRect(QTextCursor(block)).bottom();
        
        drawLineNumber(lineNumber, y, painter);
    }
}

void QLineNumberRuler::paintEvent(QPaintEvent *event) {
    printf("QLineNumberRuler paint event\n");
    QPainter painter(this);
    // FIXME: Make the color settable
    auto backgroundColor = QColor(Qt::GlobalColor::lightGray);
    painter.fillRect(event->rect(), backgroundColor);
    
    drawLineNumbersInRect(event->rect());
    drawMarkersInRect(event->rect());
}

void QLineNumberRuler::drawMarkersInRect(QRectF aRect) {
    for (auto iterator = _markers->begin(); iterator != _markers->end(); ++iterator) {
        (*iterator)->drawRect(aRect);
    }
}

qreal QLineNumberRuler::ruleThickness() const {
    return _ruleThickness;
}

void QLineNumberRuler::setRuleThickness(qreal thickness) {
    _ruleThickness = thickness;
    _codeEdit->tile();
}

qreal QLineNumberRuler::reservedThicknessForMarkers() const {
    return _reservedThicknessForMarkers;
}

void QLineNumberRuler::setReservedThicknessForMarkers(qreal thickness) {
    _reservedThicknessForMarkers = thickness;
    _codeEdit->tile();
}

qreal QLineNumberRuler::reservedThicknessForAccessoryWidget() const {
    return _reservedThicknessForMarkers;
}

void QLineNumberRuler::setReservedThicknessForAccessoryWidget(qreal thickness) {
    _reservedThicknessForAccessoryWidget = thickness;
    _codeEdit->tile();
}

qreal QLineNumberRuler::requiredThickness() const {
    return ruleThickness() + reservedThicknessForMarkers() + reservedThicknessForAccessoryWidget();
}
