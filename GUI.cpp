#include "GUI.h"

GUI::GUI(QWidget *parent)
    : QDialog(parent),
	layout(new QVBoxLayout),
	label(new QLabel("Input file hasn't selected")),
	lineConverteFile(new QLineEdit),
	selectFile(new QPushButton("Select File")),
	convertFile(new QPushButton("Convert File")),
	splitter(new QSplitter(Qt::Vertical)),
	pte(new QTextEdit),
	fileIsSelected(false)
{
	setWindowTitle("txt-csv converter");

	selectFile->setMinimumSize(QSize(60,40));
	convertFile->setMinimumSize(QSize(60, 40));
	
	lineConverteFile->setMinimumSize(QSize(50,25));

	lineConverteFile->setPlaceholderText(QString("Type output file name"));

	label->setBuddy(selectFile);
	layout->addWidget(label);
	layout->addWidget(selectFile);
	layout->addWidget(lineConverteFile);
	layout->addWidget(convertFile);
	layout->addWidget(splitter);
	
	pte->setReadOnly(true);
	splitter->addWidget(pte);

	connect(selectFile, SIGNAL(clicked()), this, SLOT(selectFileClicled()));
	connect(convertFile, SIGNAL(clicked()), this, SLOT(convertFileClicled()));

	setLayout(layout);
}

void GUI::selectFileClicled()
{
	QString s = QFileDialog::getOpenFileUrl(this, QString(), QUrl(), "*.txt").toString();
	if (s.size() > 0)
	{
		path = s.toStdString();
		path.erase(0, 8);
		int pos = s.lastIndexOf('/');
		qPath = s.left(pos + 1);
		qPath = qPath.remove(0, 8);
		name = s.remove(0, pos + 1);
		label->setText(name + " file has been selected");
		fileIsSelected = true;
	}
}

void GUI::convertFileClicled()
{
	if (fileIsSelected)
	{
		try
		{

			IConverter* converter = new TextToCsvConverter;
			converter->convert(path, false);
			std::string convertPath = qPath.toStdString();
			
			if (lineConverteFile->text().size() > 0)
			{
				convertPath += lineConverteFile->text().toStdString();
				convertPath += ".csv";
			}
			else
			{
				convertPath += "output.csv";
			}
			converter->write(convertPath);
			printWarnings(converter);
		}
		catch (FormatException ex)
		{
			QMessageBox::information(this, "Exeption", ex.what().c_str());
		}
	}
	else
	{
		QMessageBox::information(this, "Warning", "File hasn't selected");
	}
}

void GUI::printWarnings(IConverter* converter)
{
	QString s1,s2;
	for (int i = 0; i < converter->getWarnings().size(); ++i)
	{
		s1 = QString::fromUtf8(converter->getWarnings().at(i).warning.c_str());
		s2 += s1;
		s2 += "\n";
	}
		pte->setPlainText(s2);
}