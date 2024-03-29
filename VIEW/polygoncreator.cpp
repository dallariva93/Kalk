#include "polygoncreator.h"
#include <QComboBox>
PolygonCreator::PolygonCreator(OperandSelector *opSel,  QWidget *parent) : QWidget(parent),selettore(opSel){
/*    QSize size(390,350), buttonSize(100,25);
    setMaximumSize(size);
    setMinimumSize(size);*/
    QSize buttonSize(100,25);


    triangleWidget=new TriangleCreator(selettore);
    quadrilateralWidget=new QuadrilateralCreator( selettore);
    pentagonWidget=new PentagonCreator( selettore);

    triangleButton=new QPushButton("Triangolo");
    quadrilateralButton= new QPushButton("Quadrilatero");
    pentagonButton= new QPushButton("Pentagono");

    triangleButton->setMaximumSize(buttonSize);
    quadrilateralButton->setMaximumSize(buttonSize);
    pentagonButton->setMaximumSize(buttonSize);

    buttonsLayout=new QHBoxLayout;
    mainLayout=new QVBoxLayout;

    quadrilateralWidget->setVisible(false);
    pentagonWidget->setVisible(false);

    connect(triangleButton, SIGNAL(clicked()), triangleWidget, SLOT(show()));
    connect(triangleButton, SIGNAL(clicked()), quadrilateralWidget, SLOT(close()));
    connect(triangleButton, SIGNAL(clicked()),pentagonWidget,SLOT(close()));
    connect(quadrilateralButton, SIGNAL(clicked()), triangleWidget, SLOT(close()));
    connect(quadrilateralButton, SIGNAL(clicked()), quadrilateralWidget, SLOT(show()));
    connect(quadrilateralButton, SIGNAL(clicked()),pentagonWidget,SLOT(close()));
    connect(pentagonButton, SIGNAL(clicked()), triangleWidget, SLOT(close()));
    connect(pentagonButton, SIGNAL(clicked()), quadrilateralWidget, SLOT(close()));
    connect(pentagonButton, SIGNAL(clicked()),pentagonWidget,SLOT(show()));


    buttonsLayout->addWidget(triangleButton);
    buttonsLayout->addWidget(quadrilateralButton);
    buttonsLayout->addWidget(pentagonButton);

    mainLayout->addLayout(buttonsLayout);
    mainLayout->addWidget(triangleWidget);
    mainLayout->addWidget(quadrilateralWidget);
    mainLayout->addWidget(pentagonWidget);
    setLayout(mainLayout);
}

void PolygonCreator::refreshCreators(){
    mainLayout->removeWidget(triangleWidget);
    mainLayout->removeWidget(quadrilateralWidget);
    mainLayout->removeWidget(pentagonWidget);

    delete triangleWidget;
    delete quadrilateralWidget;
    delete pentagonWidget;

    triangleWidget = new TriangleCreator(selettore);
    quadrilateralWidget = new QuadrilateralCreator( selettore);
    pentagonWidget = new PentagonCreator(selettore);
}

PolygonCreator::~PolygonCreator()
{
    delete triangleWidget;
    delete quadrilateralWidget;
    delete pentagonWidget;
    delete triangleButton;
    delete quadrilateralButton;
    delete pentagonButton;
    delete buttonsLayout;
    delete mainLayout;

}


void PolygonCreator::triangleSlot(){
    refreshCreators();
    mainLayout->addWidget(triangleWidget);
}

void PolygonCreator::quadrilateralSlot(){
    refreshCreators();
    mainLayout->addWidget((quadrilateralWidget));
}

void PolygonCreator::pentagonSlot(){
    refreshCreators();
    mainLayout->addWidget(pentagonWidget);
}

void PolygonCreator::addColore(Colore *colore){
    QPixmap pmap(20,15);
    pmap.fill(colore->toQcolor());
    QIcon icon(pmap);
    triangleWidget->inserisciColore(icon,colore->getHex());
    quadrilateralWidget->inserisciColore(icon,colore->getHex());
    pentagonWidget->inserisciColore(icon,colore->getHex());
}

