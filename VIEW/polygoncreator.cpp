#include "polygoncreator.h"

PolygonCreator::PolygonCreator(OperandSelector *opSel, QWidget *parent) : selettore(opSel),QWidget(parent){
/*    QSize size(390,350), buttonSize(100,25);
    setMaximumSize(size);
    setMinimumSize(size);*/
    QSize buttonSize(100,25);

    colori=new QComboBox;

    triangleWidget=new TriangleCreator(colori, selettore);
    quadrilateralWidget=new QuadrilateralCreator(colori, selettore);
    pentagonWidget=new PentagonCreator(colori, selettore);

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

    connect(triangleButton, SIGNAL(clicked()), colori, SLOT(show()));
    connect(quadrilateralButton, SIGNAL(clicked()), colori, SLOT(show()));
    connect(pentagonButton, SIGNAL(clicked()),colori,SLOT(show()));

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

    triangleWidget = new TriangleCreator(colori, selettore);
    quadrilateralWidget = new QuadrilateralCreator(colori, selettore);
    pentagonWidget = new PentagonCreator(colori, selettore);
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
    colori->addItem(icon,colore->getHex());
}

