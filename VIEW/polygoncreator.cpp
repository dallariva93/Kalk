#include "polygoncreator.h"

PolygonCreator::PolygonCreator(QWidget *parent) : QWidget(parent)
{
    QSize size(400,250), buttonSize(100,25);
    setMaximumSize(size);
    setMinimumSize(size);

    triangleWidget=new TriangleCreator;
    quadrilateralWidget=new QuadrilateralCreator;
    pentagonWidget=new PentagonCreator;

    triangleButton=new QPushButton;
    quadrilateralButton= new QPushButton;
    pentagonButton= new QPushButton;

    triangleButton->setText("Triangolo");
    triangleButton->setMaximumSize(buttonSize);
    quadrilateralButton->setText("Quadrilatero");
    quadrilateralButton->setMaximumSize(buttonSize);
    pentagonButton->setText("Pentagono");
    pentagonButton->setMaximumSize(buttonSize);



    buttonsLayout=new QHBoxLayout;
    buttonsLayout->setMargin(-2);
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

