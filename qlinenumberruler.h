//
//  qrulermarker.h
//  QLineNumberRuler
//
//  Created by Sergej Jaskiewicz on 10.12.16.
//
//

#ifndef QLINENUMBERRULER_H
#define QLINENUMBERRULER_H

#include <QWidget>
#include <QTextEdit>

class QRulerMarker;

class QLineNumberRuler : public QWidget {
    Q_OBJECT
    
public:
    QLineNumberRuler(QTextEdit *aScrollArea);                       // -initWithScrollView:
    
    QTextEdit* textEdit() const;                                    // -scrollView:
    
    QVector<QRulerMarker*>* markers() const;                        // -markers:
    void setMarkers(QVector<QRulerMarker*>* newMarkers);            // -setMarkers:
    void addMarker(QRulerMarker *aMarker);                          // -addMarker:
    void removeMarker(QRulerMarker *aMarker);
    void trackMarker(QRulerMarker *aMarker, QMouseEvent *theEvent); // -trackMarker:withMouseEvent:
    
    void drawLineNumbersInRect(QRectF aRect);                       // -drawHashMarksAndLabelsInRect:
    void drawMarkersInRect(QRectF aRect);                           // -drawMarkersInRect:
    
    qreal ruleThickness() const;                                    // -ruleThickness:
    void setRuleThickness(qreal thickness);                         // -setRuleThickness:
    
    qreal reservedThicknessForMarkers() const;                      // -reservedThicknessForMarkers:
    void setReservedThicknessForMarkers(qreal thickness);           // -setReservedThicknessForMarkers:
    
    qreal requiredThickness() const;                                // -requiredThickness:
    
    ~QLineNumberRuler() {
        delete _markers;
    }
    
private:
    QTextEdit *_textEdit;
    QVector<QRulerMarker*> *_markers;
    qreal _reservedThicknessForMarkers;
    qreal _ruleThickness;
    qreal _requiredThickness;
};

#endif // QLINENUMBERRULER_H
