#ifndef BIT_WIDGET__H
#define BIT_WIDGET__H

#include <QWidget>
#include <QList>
#include <QCheckBox>

class BitWidget: public QWidget {
  
  Q_OBJECT

  QList< QCheckBox*> _checkList;
  int		     _bitMask;
  public:
  	BitWidget();
	int bitMask();
	
  private slots:
	void changeBit( int i );


};
#endif
