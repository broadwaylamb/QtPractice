//
//  qrulermarker.h
//  QLineNumberRuler
//
//  Created by Sergej Jaskiewicz on 10.12.16.
//
//

#ifndef qrulermarker_h
#define qrulermarker_h

#include <QObject>
#include <QObject>
#include <QImage>
#include "qlinenumberruler.h"

class QRulerMarker : public QObject {
    Q_OBJECT
    
public:
    QRulerMarker(QLineNumberRuler *aRuler,
                 qreal markerLocation,
                 QImage anImage,
                 QPointF imageOririn);                  // -initWithRulerView:markerLocation:image:imageOrigin:
    
    QLineNumberRuler* ruler() const;                    // -ruler
    
    QImage* image() const;                              // -image
    void setImage(QImage *anImage);                     // -setImage:
    
    void setImageOrigin(QPointF aPoint);                // -setImageOrigin:
    QPointF imageOrigin() const;                        // -imageOrigin
    
    QRectF imageRectInRuler() const;                    // -imageRectInRuler
    
    qreal thicknessRequiredInRuler() const;             // -thicknessRequiredInRuler
    
    void setMovable(bool flag);                         // -setMovable:
    bool isMovable() const;                             // -isMovable
    void setRemovable(bool flag);                       // -setRemovable:
    bool isRemovable() const;                           // -isRemovable
    
    void setMarkerLocation(qreal location);             // -setMarkerLocation:
    qreal markerLocation() const;                       // -markerLocation
    
    void setRepresentedObject(QObject *anObject);       // -setRepresentedObject:
    QObject* representedObject() const;                 // -representedObject
    
    void drawRect(QRectF aRect);                        // -drawRect:
    bool isDragging();                                  // -isDragging
    bool trackMouse(QMouseEvent *theEvent, bool adding);// -trackMouse:adding:
    
private:
    QRulerMarker(QLineNumberRuler *aRuler);
    QLineNumberRuler *_ruler;
    QImage *_image;
    QObject *_representedObject;
    QPointF *_imageOrigin;
    qreal _location;
    bool _isMovable;
    bool _isRemovable;
    bool _isDragging;
};

#endif /* qrulermarker_h */
