#include "polygoncreator.h"

PolygonCreator::PolygonCreator(QWidget *parent) : QWidget(parent)
{
/*    QSize size(390,350), buttonSize(100,25);
    setMaximumSize(size);
    setMinimumSize(size);*/
    QSize buttonSize(100,25);

    triangleWidget=new TriangleCreator;
    quadrilateralWidget=new QuadrilateralCreator;
    pentagonWidget=new PentagonCreator;

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

    buttonsLayout->addWidget(triangleButton);
    buttonsLayout->addWidget(quadrilateralButton);
    buttonsLayout->addWidget(pentagonButton);

    mainLayout->addLayout(buttonsLayout);
    mainLayout->addWidget(triangleWidget);
    mainLayout->addWidget(quadrilateralWidget);
    mainLayout->addWidget(pentagonWidget);
    setLayout(mainLayout);


}

void PolygonCreator::refreshCreators()
{
    mainLayout->removeWidget(triangleWidget);
    mainLayout->removeWidget(quadrilateralWidget);
    mainLayout->removeWidget(pentagonWidget);

    delete triangleWidget;
    delete quadrilateralWidget;
    delete pentagonWidget;

    triangleWidget = new TriangleCreator;
    quadrilateralWidget = new QuadrilateralCreator;
    pentagonWidget = new PentagonCreator;
}

void PolygonCreator::triangleSlot(bool)
{
    refreshCreators();
    mainLayout->addWidget(triangleWidget);

}

void PolygonCreator::quadrilateralSlot(bool)
{
    refreshCreators();
    mainLayout->addWidget((quadrilateralWidget));

}

void PolygonCreator::pentagonSlot(bool)
{
    refreshCreators();
    mainLayout->addWidget(pentagonWidget);
}

