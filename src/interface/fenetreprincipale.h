#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include "fenetreparametres.h"
#include <QMainWindow>
#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>
#include "RecoManager.h"

extern Configuration parametres;

namespace Ui {
    class FenetrePrincipale;
}

class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

    public:
        explicit FenetrePrincipale(QWidget *parent = 0);
        ~FenetrePrincipale();
        void configuration();
        virtual void lectureVideo();
        virtual void arretVideo();
        bool getPlay() {return play;}
        QString getNomAction(string nom);
        QString getNomPlan(string nom);
        QString getLogo(string nom);

    protected:
        void closeEvent(QCloseEvent *event) override;

    public slots:
        void gestionVideo();
        void MiseAJourImage();
        void MiseAJourHistogramme(int position);
        void MiseAJourProgression(string timer);
        void MiseAJourInformations(std::map<std::string, std::map<std::string, std::string>> informations);
        void ouvrirFenetreParametres();
        void pleinEcranVideo();

    private:
        Ui::FenetrePrincipale *ui;
        FenetreParametres *fenetreParametres;
        RecoManager *reconnaissanceManager;
        bool play = false;
};

#endif // FENETREPRINCIPALE_H
