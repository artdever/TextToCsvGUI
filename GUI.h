#pragma once

#include <QtWidgets\QDialog>
#include <QtWidgets\QVBoxLayout>
#include <QtWidgets\qlabel.h>
#include <QtWidgets\qlineedit.h>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qfiledialog.h>
#include <QtWidgets\qsplitter.h>
#include <QtWidgets\qtextEdit.h>
#include <qmessagebox.h>
#include <qprocess.h>
#include <qstring.h>

#include "IConverter.h"
#include "TextToCsvConverter.h"

#include <iostream>

class GUI : public QDialog
{
    Q_OBJECT

public:
    GUI(QWidget *parent = Q_NULLPTR);

private slots:
	void selectFileClicled();
	void convertFileClicled();
	void printWarnings(IConverter* converter);

private:
	QVBoxLayout* layout;

	QLabel* label;
	QLineEdit* lineConverteFile;

	QPushButton* selectFile;
	QPushButton* convertFile;

	QSplitter* splitter;
	QTextEdit* pte;

	QString name;
	QString qPath;
	std::string path;

	bool fileIsSelected;
};
