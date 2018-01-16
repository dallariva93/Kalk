#include "polygoncreator.h"

PolygonCreator::PolygonCreator(QWidget *parent) : QWidget(parent){
/*    QSize size(390,350), buttonSize(100,25);
    setMaximumSize(size);
    setMinimumSize(size);*/
    QSize buttonSize(100,25);

    colori=new QComboBox;

    triangleWidget=new TriangleCreator(colori);
    quadrilateralWidget=new QuadrilateralCreator(colori);
    pentagonWidget=new PentagonCreator(colori);

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
/*
    connect(triangleButton, SIGNAL(clicked(bool)),this, SLOT(triangleSlot(bool)));
    connect(quadrilateralButton, SIGNAL(clicked(bool)), this, SLOT(quadrilateralSlot(bool)));
    connect(pentagonButton, SIGNAL(clicked(bool)), this, SLOT(pentagonSlot(bool)));
    connect(triangleButton, SIGNAL(clicked(bool)),triangleWidget, SLOT(setVisible(bool)));
    connect(triangleButton, SIGNAL(clicked(bool)),quadrilateralWidget, SLOT(setHidden(bool)));
    connect(triangleButton, SIGNAL(clicked(bool)),pentagonWidget, SLOT(setHidden(bool)));
    connect(quadrilateralButton, SIGNAL(clicked(bool)),quadrilateralWidget, SLOT(setVisible(bool)));
    connect(quadrilateralButton, SIGNAL(clicked(bool)),triangleWidget, SLOT(setHidden(bool)));
    connect(quadrilateralButton, SIGNAL(clicked(bool)),pentagonWidget, SLOT(setHidden(bool)));
    connect(pentagonButton, SIGNAL(clicked(bool)),pentagonWidget, SLOT(setVisible(bool)));
    connect(pentagonButton, SIGNAL(clicked(bool)),triangleWidget, SLOT(setHidden(bool)));
    connect(pentagonButton, SIGNAL(clicked(bool)),quadrilateralWidget, SLOT(setHidden(bool)));
*/
    connect(triangleButton, SIGNAL(clicked()), triangleWidget, SLOT(show()));
    connect(triangleButton, SIGNAL(clicked()), quadrilateralWidget, SLOT(close()));
    connect(triangleButton, SIGNAL(clicked(bool)),pentagonWidget,SLOT(close()));
    connect(quadrilateralButton, SIGNAL(clicked()), triangleWidget, SLOT(close()));
    connect(quadrilateralButton, SIGNAL(clicked()), quadrilateralWidget, SLOT(show()));
    connect(quadrilateralButton, SIGNAL(clicked(bool)),pentagonWidget,SLOT(close()));
    connect(pentagonButton, SIGNAL(clicked()), triangleWidget, SLOT(close()));
    connect(pentagonButton, SIGNAL(clicked()), quadrilateralWidget, SLOT(close()));
    connect(pentagonButton, SIGNAL(clicked(bool)),pentagonWidget,SLOT(show()));

    connect(triangleButton, SIGNAL(clicked()), colori, SLOT(show()));
    connect(quadrilateralButton, SIGNAL(clicked()), colori, SLOT(show()));
    connect(pentagonButton, SIGNAL(clicked(bool)),colori,SLOT(show()));





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

    QComboBox* temp=colori;
    delete triangleWidget;
    delete quadrilateralWidget;
    delete pentagonWidget;
    colori=temp;


    triangleWidget = new TriangleCreator(colori);
    quadrilateralWidget = new QuadrilateralCreator(colori);
    pentagonWidget = new PentagonCreator(colori);
}


void PolygonCreator::triangleSlot(bool){
    refreshCreators();
    mainLayout->addWidget(triangleWidget);
}

void PolygonCreator::quadrilateralSlot(bool){
    refreshCreators();
    mainLayout->addWidget((quadrilateralWidget));
}

void PolygonCreator::pentagonSlot(bool){
    refreshCreators();
    mainLayout->addWidget(pentagonWidget);
}

void PolygonCreator::addColore(Colore *colore)
{
    QPixmap pmap(20,15);
    pmap.fill(colore->toQcolor());
    QIcon icon(pmap);
    colori->addItem(icon,colore->getHex());
}

