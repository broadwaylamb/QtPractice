//
//  QCodeEdit.h
//  QLineNumberRuler
//
//  Created by Sergej Jaskiewicz on 25.12.16.
//
//

#ifndef QCodeEdit_h
#define QCodeEdit_h

#include <QTextEdit>
#include "qlinenumberruler.h"

class QCodeEdit : public QTextEdit {
    Q_OBJECT
public:
    explicit QCodeEdit(QWidget *parent = nullptr);

    void tile();
    void setHasLineNumberRuler(bool flag);
    bool hasLineNumberRuler() const;
    void setRulerVisible(bool flag);
    bool isRulerVisible() const;
    void setLineNumberRuler(QLineNumberRuler *ruler);
    QLineNumberRuler* lineNumberRuler() const;
    
protected:
    virtual void wheelEvent(QWheelEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;
    
private:
    QLineNumberRuler *_ruler;
    bool _hasLineNumberRuler;
    bool _isRulerVisible;
};

#endif /* QCodeEdit_h */
