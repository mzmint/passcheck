#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <cmath>
#include <QPainter>
#include <QTabWidget>
#include <QDebug>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <iostream>
#include <cstdlib>
#include <ctime>

int numcheck(QLineEdit &pass) {
    QString text = pass.text();
    int points = 0;
    for (int i = 0; i < text.length(); i++) {
        QChar c = text.at(i);
        if (c.isDigit()) {
            points++;
        }
    }
    if (points > 10) {
        points = 10;
    }
    return points;
}

int uppCase(QLineEdit &pass) {
    QString text = pass.text();
    int points = 0;
    for (int i = 0; i < text.length(); i++) {
        QChar c = text.at(i);
        if (c.isUpper()) {
            points++;
        }
    }
    if (points > 10) {
        points = 10;
    }
    return points;
}

int lowCase(QLineEdit &pass) {
    QString text = pass.text();
    int points = 0;
    for (int i = 0; i < text.length(); i++) {
        QChar c = text.at(i);
        if (c.isLower()) {
            points++;
        }
    }
    if (points > 10) {
        points = 10;
    }
    return points;
}

int main(int argc, char *argv[]) {

    int sp = 0;


    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("PassCheck");
    window.resize(1920, 1080);
    window.show();

    QLineEdit pass;
    pass.setFixedWidth(540);

    QPushButton check;
    check.setFixedWidth(540);
    check.setText("Check");

    QLabel strength;
    strength.setFixedWidth(540);

    QObject::connect(&check, &QPushButton::clicked, [&]() {
        sp = pass.text().length();
        if (sp > 16) {
            sp = 16;
        }
        sp += numcheck(pass);
        sp += uppCase(pass);
        sp += lowCase(pass);
        strength.setText(QString::number(sp) + "/46");
    });

    QGridLayout layout;
    layout.addWidget(&pass, 0, 0);
    layout.addWidget(&check, 1, 0);
    layout.addWidget(&strength, 2, 0);
    window.setLayout(&layout);

    return app.exec();
}