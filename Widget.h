#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>

class SearchHighLight;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_addFile_clicked();

private:
    // Slot to handle the pressing of the button to install the desired text
    void onSearchText();

    Ui::Widget *ui;
    // Inherited class for creating syntax highlighting logic
    SearchHighLight* m_searchHighLight;
    QFile *destinationFile;
};

#endif // WIDGET_H
