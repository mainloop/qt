#include <QSignalMapper>
#include <QHBoxLayout>
#include <QString>
#include <QDebug>

#include "bitwidget.h"


BitWidget::BitWidget() :
  QWidget(),
  _bitMask(0)
{

  QSignalMapper *signalMapper = new QSignalMapper(this);
  QHBoxLayout *layout = new QHBoxLayout;


  for( int i=0; i < 8; i++ ) {
    QCheckBox *checkBox = new QCheckBox;
    checkBox->setText( QString("Bit %1").arg(i) );
	
    _checkList << checkBox;

    layout->addWidget( checkBox );

    signalMapper->setMapping( checkBox, i );
    
    connect( checkBox,SIGNAL(clicked()),signalMapper,SLOT(map()));
  }

  connect(signalMapper, SIGNAL(mapped(int)), this, SLOT( changeBit(int)));


  setLayout(layout);
}

void BitWidget::changeBit( int i )
{
  if( _checkList.at(i)->isChecked() ) {
    _bitMask |=  (1<<i);
  }
  else {
    _bitMask &= ~(1<<i);
  }

  qDebug() << _bitMask;
}

int BitWidget::bitMask()
{
  return _bitMask;
}


