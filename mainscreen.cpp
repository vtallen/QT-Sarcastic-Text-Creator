#include "mainscreen.h"
#include "./ui_mainscreen.h"

#include <QDebug>

MainScreen::MainScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainScreen)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), SLOT(processText()));
}

MainScreen::~MainScreen()
{
    delete ui;
}

void MainScreen::processText() {
    ui->outputTextEdit->clear();
    QString startingText{ui->inputTextEdit->toPlainText()};
    QString resultText{};

    bool makeUpper{false};

    for (auto character : startingText) {
        if (character == ' ') {
            resultText += " ";
            continue;
        }

        if (makeUpper) {
            resultText += character.toUpper();
            makeUpper = false;
        } else {
            resultText += character.toLower();
            makeUpper = true;
        }

        ui->outputTextEdit->setText(resultText);
    }
}

