/****************************************************************************
**
** Copyright (C) 2014-2016 Dinu SV.
** (contact: mail@dinusv.com)
** This file is part of Live CV Application.
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
****************************************************************************/

#ifndef QMATBUFFER_HPP
#define QMATBUFFER_HPP

#include <QQuickItem>
#include "qlcvglobal.h"
#include "qmatdisplay.h"

class QMatBuffer : public QMatDisplay{

    Q_OBJECT
    Q_PROPERTY( QMat* input READ inputMat WRITE setInputMat NOTIFY inputChanged )

public:
    explicit QMatBuffer(QQuickItem *parent = 0);
    ~QMatBuffer();

    void setInputMat(QMat* input);
    QMat* inputMat();

signals:
    void inputChanged();

private:
    QMat* m_matBuffer;
    QMat* m_matCurrent;

};


inline void QMatBuffer::setInputMat(QMat *input){
    if ( input == 0 )
        return;

    m_matCurrent->cvMat()->copyTo(*m_matBuffer->cvMat());
    input->cvMat()->copyTo(*m_matCurrent->cvMat());
    emit inputChanged();
    setOutput(m_matBuffer);
    update();
}

inline QMat *QMatBuffer::inputMat(){
    return m_matCurrent;
}

#endif // QMATBUFFER_HPP
