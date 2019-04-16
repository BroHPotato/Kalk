#ifndef LCD_H
#define LCD_H

#include <QWidget>

class lcd : public QWidget
{
    Q_OBJECT
public:
    explicit lcd(QWidget *parent = NULL);
signals:
public slots:
private:
    QString s;
};

#endif // LCD_H
