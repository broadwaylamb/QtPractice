//
//  qrulermarker.h
//  QLineNumberRuler
//
//  Created by Sergej Jaskiewicz on 10.12.16.
//
//

#include "qlinenumberruler.h"

QLineNumberRuler::QLineNumberRuler(QTextEdit *aTextEdit) : QWidget(aTextEdit) {
    
    _textEdit = aTextEdit;
    setMarkers(new QVector<QRulerMarker*>(0));
}

QTextEdit* QLineNumberRuler::textEdit() const {
    return _textEdit;
}

QVector<QRulerMarker*>* QLineNumberRuler::markers() const {
    return _markers;
}

void QLineNumberRuler::setMarkers(QVector<QRulerMarker*>* newMarkers) {
    delete _markers;
    _markers = newMarkers;
}

void QLineNumberRuler::addMarker(QRulerMarker *aMarker) {
    Q_UNUSED(aMarker)
}

void QLineNumberRuler::removeMarker(QRulerMarker *aMarker) {
    Q_UNUSED(aMarker)
}

void QLineNumberRuler::trackMarker(QRulerMarker *aMarker, QMouseEvent *theEvent) {
    Q_UNUSED(aMarker)
    Q_UNUSED(theEvent)
}

void QLineNumberRuler::drawLineNumbersInRect(QRectF aRect) {
    Q_UNUSED(aRect)
}

void drawMarkersInRect(QRectF aRect) {
    Q_UNUSED(aRect)
}

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
