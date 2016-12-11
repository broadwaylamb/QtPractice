//
//  qrulermarker.h
//  QLineNumberRuler
//
//  Created by Sergej Jaskiewicz on 10.12.16.
//
//

#include "qlinenumberruler.h"
#include "qrulermarker.h"
#include <QVector>

#define RULER_THICKNESS 16

// TODO: Implement accessory view

// MARK: Implemented
QLineNumberRuler::QLineNumberRuler(QTextEdit *aTextEdit) : QWidget(aTextEdit) {
    
    setTextEdit(aTextEdit);
    setRuleThickness(RULER_THICKNESS);
    setReservedThicknessForMarkers(0.0);
    setReservedThicknessForAccessoryWidget(0.0);
    setMarkers(new QVector<QRulerMarker*>(0));
}

void QLineNumberRuler::setAccessoryWidget(QWidget *aWidget) {
    // TODO: support for accessory widgets is not implemented
    _accessoryWidget = aWidget;
}

// MARK: Implemented
QWidget* QLineNumberRuler::accessoryWidget() const {
    return _accessoryWidget;
}

// MARK: Implemented
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

// MARK: Implemented
void QLineNumberRuler::setMarkers(QVector<QRulerMarker*>* newMarkers) {
    _markers = newMarkers;
    update();
}

// MARK: Implemented
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

// MARK: Implemented
void QLineNumberRuler::removeMarker(QRulerMarker *aMarker) {
    if (_markers == nullptr) {
        return;
    }
    
    _markers->removeOne(aMarker);
    
    update();
}

// MARK: Implemented
bool QLineNumberRuler::trackMarker(QRulerMarker *aMarker, QMouseEvent *theEvent) {
    if (aMarker == nullptr) {
        return false;
    }
    
    return aMarker->trackMouse(theEvent, true);
}

// MARK: Implemented
QTextEdit* QLineNumberRuler::textEdit() const {
    return _textEdit;
}

// MARK: Implemented
void QLineNumberRuler::setTextEdit(QTextEdit *aTextEdit) {
    _textEdit = aTextEdit;
}

// MARK: Implemented
QVector<QRulerMarker*>* QLineNumberRuler::markers() const {
    return _markers;
}

void QLineNumberRuler::drawLineNumbersInRect(QRectF aRect) {
    Q_UNUSED(aRect)
}

// MARK: Implemented
void QLineNumberRuler::drawMarkersInRect(QRectF aRect) {
    for (auto iterator = _markers->begin(); iterator != _markers->end(); ++iterator) {
        (*iterator)->drawRect(aRect);
    }
}

// MARK: Implemented
qreal QLineNumberRuler::ruleThickness() const {
    return _ruleThickness;
}

void QLineNumberRuler::setRuleThickness(qreal thickness) {
    _ruleThickness = thickness;
}

qreal QLineNumberRuler::reservedThicknessForMarkers() const {
    return _reservedThicknessForMarkers;
}

void QLineNumberRuler::setReservedThicknessForMarkers(qreal thickness) {
    _reservedThicknessForMarkers = thickness;
}

qreal QLineNumberRuler::reservedThicknessForAccessoryWidget() const {
    return  _reservedThicknessForMarkers;
}

void QLineNumberRuler::setReservedThicknessForAccessoryWidget(qreal thickness) {
    _reservedThicknessForAccessoryWidget = thickness;
}

// MARK: Implemented
qreal QLineNumberRuler::requiredThickness() const {
    return ruleThickness() + reservedThicknessForMarkers() + reservedThicknessForAccessoryWidget();
}
