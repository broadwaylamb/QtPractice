//
//  qrulermarker.cpp
//  QLineNumberRuler
//
//  Created by Sergej Jaskiewicz on 10.12.16.
//
//

#include "qrulermarker.h"

QRulerMarker::QRulerMarker(QLineNumberRuler *aRuler,
                           qreal markerLocation,
                           QImage anImage,
                           QPointF imageOririn) {
    
}

QLineNumberRuler* QRulerMarker::ruler() const {
    
}

QImage* QRulerMarker::image() const {
    
}
void QRulerMarker::setImage(QImage *anImage) {
    
}

void QRulerMarker::setImageOrigin(QPointF aPoint) {
    
}

QPointF QRulerMarker::imageOrigin() const {
    
}

QRectF QRulerMarker::imageRectInRuler() const {
    
}

qreal QRulerMarker::thicknessRequiredInRuler() const {
    
}

void QRulerMarker::setMovable(bool flag) {
    
}

bool QRulerMarker::isMovable() const {
    
}

void QRulerMarker::setRemovable(bool flag) {
    
}

bool QRulerMarker::isRemovable() const {
    
}

void QRulerMarker::setMarkerLocation(qreal location) {
    
}

qreal QRulerMarker::markerLocation() const {
    
}

void QRulerMarker::setRepresentedObject(QObject *anObject) {
    
}

QObject* QRulerMarker::representedObject() const {
    
}

void QRulerMarker::drawRect(QRectF aRect) {
    
}

bool QRulerMarker::isDragging() {
    
}

bool QRulerMarker::trackMouse(QMouseEvent *theEvent, bool adding) {
    
}
