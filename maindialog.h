#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>

class MainDialog : public QDialog
{
    Q_OBJECT
private:
    QLabel* m_mainImage;
    QLabel* m_puzzlePiece;
    QPushButton* m_selectPieceButton;
    QPushButton* m_detectButton;
	QString m_wholeImagePath;
	QString m_puzzlePiecePath;

    QLabel* m_result;
private slots:
    void uploadImageClicked();
    void uploadPuzzlePieceClicked();
	void process();
	void capture();

public:
    MainDialog(QWidget *parent = 0);
    ~MainDialog();
};

#endif // MAINDIALOG_H
