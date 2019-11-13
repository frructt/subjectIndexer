#include "Widget.h"
#include "ui_Widget.h"

#include "SearchHighLight.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    destinationFile = new QFile;

    ui->showText->setReadOnly(true);
    // Create and initialize search highlighting
    m_searchHighLight = new SearchHighLight(ui->showText->document());

    // We connect the signal of the button to the slots for calling the search.
//    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::onSearchText);
    connect(ui->searchWord, &QPushButton::clicked, this, &Widget::onSearchText);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::onSearchText()
{
    // We load the text for search in syntax highlighting
    m_searchHighLight->searchText(ui->wordLine->text());
//    ui->subjectIndex->setText(ui->wordLine->text());
    ui->subjectIndex->insertPlainText(ui->wordLine->text());
    ui->subjectIndex->insertPlainText("\n");
}

void Widget::on_addFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Take a txt file"),
                                                    "/home",
                                                    tr("Text files (*.txt *.docx)"));

//    ui->addFile->setVisible(false);
//    ui->showFile->setVisible(true);
//    ui->addWord->setVisible(true);

    destinationFile->setFileName(fileName);
    QByteArray data;

    if (!destinationFile->open(QIODevice::ReadOnly))
        printf("File is not open");

    data = destinationFile->readAll();
//    data = destinationFile->Append;
    ui->showText->setText(data);
}
