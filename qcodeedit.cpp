//
//  QCodeEdit.cpp
//  QLineNumberRuler
//
//  Created by Sergej Jaskiewicz on 25.12.16.
//
//

#include "qcodeedit.h"
#include <QWheelEvent>

QCodeEdit::QCodeEdit(QWidget *parent) :
QTextEdit(parent),
_ruler(nullptr),
_hasLineNumberRuler(false),
_isRulerVisible(false) {
    
    printf("QCodeEdit initialized\n");
}

void QCodeEdit::setHasLineNumberRuler(bool flag) {
    
    if (_hasLineNumberRuler == flag) {
        return;
    }
    
    _hasLineNumberRuler = flag;
    
    if (_hasLineNumberRuler && _ruler == nullptr) {
        _ruler = new QLineNumberRuler(this);
        _ruler->setVisible(false);
    }
    
    if (_isRulerVisible) {
        
        if (_hasLineNumberRuler) {
            _ruler->show();
        } else {
            _ruler->hide();
        }
        
        tile();
    }
}

bool QCodeEdit::hasLineNumberRuler() const {
    return _hasLineNumberRuler;
}

void QCodeEdit::setRulerVisible(bool flag) {
    
    if (_isRulerVisible == flag || !_hasLineNumberRuler) {
        return;
    }
    
    _isRulerVisible = flag;
    
    if (flag) {
        _ruler->show();
    } else {
        _ruler->hide();
    }
    
    tile();
}

bool QCodeEdit::isRulerVisible() const {
    return _isRulerVisible;
}

void QCodeEdit::setLineNumberRuler(QLineNumberRuler *ruler) {
    
    if (_isRulerVisible && _ruler != nullptr) {
        _ruler->hide();
    }
    
    _ruler = ruler;
    
    if (_ruler == nullptr) {
        _hasLineNumberRuler = false;
    } else if (_isRulerVisible) {
        _ruler->show();
    }
    
    if (_isRulerVisible) {
        tile();
    }
}

QLineNumberRuler* QCodeEdit::lineNumberRuler() const {
    return _ruler;
}

void QCodeEdit::tile() {
    
    printf("QCodeEdit tiled\n");
    
    if (_isRulerVisible) {
        setViewportMargins(_ruler->requiredThickness(), 0, 0, 0);
    } else {
        setViewportMargins(0, 0, 0, 0);
    }
    
    update();
}

void QCodeEdit::wheelEvent(QWheelEvent *event) {
    QTextEdit::wheelEvent(event);
    
    printf("QCodeEdit wheel event\n");
    
    if (!event->pixelDelta().isNull() || !event->angleDelta().isNull()) {
        
        if (_hasLineNumberRuler) {
            _ruler->update();
        }
    }
}

void QCodeEdit::resizeEvent(QResizeEvent *event) {
    QTextEdit::resizeEvent(event);
    
    printf("QCodeEdit resize event\n");
    
    if (_hasLineNumberRuler) {
        _ruler->setGeometry(0, 0, _ruler->requiredThickness(), height());
        _ruler->update();
    }
}
