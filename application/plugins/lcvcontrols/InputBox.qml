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

import QtQuick 2.3

Rectangle {
    width: 100
    height: 30
    border.width : 1
    border.color : "#ff0000"

    anchors.fill: parent

    property alias text : textInput.text

    TextInput{
        id : textInput
        anchors.fill: parent
        anchors.margins : 6
        font.family : "Courier New, Courier"
        font.pixelSize: 14
        font.weight : Font.Normal
        text: 'asda'
        selectByMouse: true

        MouseArea{
            anchors.fill: parent
            acceptedButtons: Qt.NoButton
            cursorShape: Qt.IBeamCursor
        }
    }
}

