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
    void setTextEdit(QTextEdit *aTextEdit);                         // -setScrollView:
    
    QWidget* accessoryWidget() const;                               // -accessoryView
    void setAccessoryWidget(QWidget *aWidget);                      // -setAccessoryWidget:
    
    QVector<QRulerMarker*>* markers() const;                        // -markers:
    void setMarkers(QVector<QRulerMarker*>* newMarkers);            // -setMarkers:
    void addMarker(QRulerMarker *aMarker);                          // -addMarker:
    void removeMarker(QRulerMarker *aMarker);
    bool trackMarker(QRulerMarker *aMarker, QMouseEvent *theEvent); // -trackMarker:withMouseEvent:
    
    void drawLineNumbersInRect(QRectF aRect);                       // -drawHashMarksAndLabelsInRect:
    void drawMarkersInRect(QRectF aRect);                           // -drawMarkersInRect:
    
    qreal reservedThicknessForAccessoryWidget() const;              // -reservedThicknessForAccessoryView
    void setReservedThicknessForAccessoryWidget(qreal thickness);   // -setReservedThicknessForAccessoryView:
    
    qreal ruleThickness() const;                                    // -ruleThickness:
    void setRuleThickness(qreal thickness);                         // -setRuleThickness:
    
    qreal reservedThicknessForMarkers() const;                      // -reservedThicknessForMarkers:
    void setReservedThicknessForMarkers(qreal thickness);           // -setReservedThicknessForMarkers:
    
    qreal requiredThickness() const;                                // -requiredThickness:
    
    ~QLineNumberRuler() {
        delete _markers;
    }
    
protected:
    
    
private:
    QTextEdit *_textEdit;
    QVector<QRulerMarker*> *_markers;
    QWidget *_accessoryWidget;
    qreal _reservedThicknessForMarkers;
    qreal _reservedThicknessForAccessoryWidget;
    qreal _ruleThickness;
    
    void _verifyReservedThicknessForMarkers();
};

#endif // QLINENUMBERRULER_H
