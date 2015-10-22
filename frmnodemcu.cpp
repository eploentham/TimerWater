#include "frmnodemcu.h"
#include "ui_frmnodemcu.h"

frmnodeMCU::frmnodeMCU(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmnodeMCU)
{
    ui->setupUi(this);
    twc = new TimerWaterControl(QApplication::applicationDirPath());
    ui->cbonodeMCU->addItem("Sensor 1", QVariant(1));
    ui->cbonodeMCU->addItem("Sensor 2", QVariant(2));
    ui->cbonodeMCU->addItem("Sensor 3", QVariant(3));
    ui->cbonodeMCU->addItem("Sensor 4", QVariant(4));
    ui->cbonodeMCU->addItem("Sensor 5", QVariant(5));
    ui->cbonodeMCU->addItem("Sensor 6", QVariant(6));
    ui->cbonodeMCU->addItem("Sensor 7", QVariant(7));
    ui->cbonodeMCU->addItem("Sensor 8", QVariant(8));
    ui->cbonodeMCU->addItem("Sensor 9", QVariant(9));
    ui->cbonodeMCU->addItem("Sensor 10", QVariant(10));
    ui->cbonodeMCU->addItem("Sensor 11", QVariant(11));
    ui->cbonodeMCU->addItem("Sensor 12", QVariant(12));
    ui->cbonodeMCU->addItem("Sensor 13", QVariant(13));
    ui->cbonodeMCU->addItem("Sensor 14", QVariant(14));
    ui->cbonodeMCU->addItem("Sensor 15", QVariant(15));
    ui->cbonodeMCU->addItem("Sensor 16", QVariant(16));
    ui->cbonodeMCU->addItem("Sensor 17", QVariant(17));
    ui->cbonodeMCU->addItem("Sensor 18", QVariant(18));
    ui->cbonodeMCU->addItem("Sensor 19", QVariant(19));
    ui->cbonodeMCU->addItem("Sensor 20", QVariant(20));
    ui->cbonodeMCU->addItem("Sensor 21", QVariant(20));
    ui->cbonodeMCU->addItem("Sensor 22", QVariant(20));
    ui->cbonodeMCU->addItem("Sensor 23", QVariant(20));
    ui->cbonodeMCU->addItem("Sensor 24", QVariant(20));
    ui->cbonodeMCU->addItem("Sensor 25", QVariant(20));
    ui->cbonodeMCU->addItem("Sensor 26", QVariant(20));
    ui->cbonodeMCU->addItem("Sensor 27", QVariant(20));
    ui->cbonodeMCU->addItem("Sensor 28", QVariant(20));
    ui->cbonodeMCU->addItem("Sensor 29", QVariant(20));
}

frmnodeMCU::~frmnodeMCU()
{
    delete ui;
}

void frmnodeMCU::on_btnSave_clicked()
{
    writeSettingnodeMCU();
}

void frmnodeMCU::writeSettingnodeMCU()
{
    nodeMCU mcu;

    mcu.Control1 = ui->txtControl1->text();
    mcu.Control2 = ui->txtControl2->text();
    mcu.Control3 = ui->txtControl3->text();
    mcu.Control4 = ui->txtControl4->text();
    mcu.Control5 = ui->txtControl5->text();
    mcu.Description = ui->txtDesc->text();
    mcu.Id = ui->txtId->text();
    mcu.ControlPort1 = ui->txtControlPort1->text();
    mcu.ControlPort2 = ui->txtControlPort2->text();
    mcu.ControlPort3 = ui->txtControlPort3->text();
    mcu.ControlPort4 = ui->txtControlPort4->text();
    mcu.ControlPort5 = ui->txtControlPort5->text();
    mcu.Sensor1 = ui->txtSensor1->text();
    mcu.Sensor2 = ui->txtSensor2->text();
    mcu.Sensor3 = ui->txtSensor3->text();
    mcu.Sensor4 = ui->txtSensor4->text();
    mcu.Sensor5 = ui->txtSensor5->text();
    mcu.SensorPort1 = ui->txtSensorPort1->text();
    mcu.SensorPort2 = ui->txtSensorPort2->text();
    mcu.SensorPort3 = ui->txtSensorPort3->text();
    mcu.SensorPort4 = ui->txtSensorPort4->text();
    mcu.SensorPort5 = ui->txtSensorPort5->text();

    twc->writeSettingnodeMCU((ui->cbonodeMCU->currentIndex()+1),mcu);
}

void frmnodeMCU::readSettingnodeMCU(int row)
{
    nodeMCU mcu;
    mcu = twc->readSettingnodeMCU(row);
    //qDebug()<<"active "+mcu.Active;

    ui->txtControl1->setText(mcu.Control1);
    ui->txtControl2->setText(mcu.Control2);
    ui->txtControl3->setText(mcu.Control3);
    ui->txtControl4->setText(mcu.Control4);
    ui->txtControl5->setText(mcu.Control5);
    ui->txtControlPort1->setText(mcu.ControlPort1);
    ui->txtControlPort2->setText(mcu.ControlPort2);
    ui->txtControlPort3->setText(mcu.ControlPort3);
    ui->txtControlPort4->setText(mcu.ControlPort4);
    ui->txtControlPort5->setText(mcu.ControlPort5);
    ui->txtDesc->setText(mcu.Description);
    ui->txtId->setText(mcu.Id);
    ui->txtSensor1->setText(mcu.Sensor1);
    ui->txtSensor2->setText(mcu.Sensor2);
    ui->txtSensor3->setText(mcu.Sensor3);
    ui->txtSensor4->setText(mcu.Sensor4);
    ui->txtSensor5->setText(mcu.Sensor5);
    ui->txtSensorPort1->setText(mcu.SensorPort1);
    ui->txtSensorPort2->setText(mcu.SensorPort2);
    ui->txtSensorPort3->setText(mcu.SensorPort3);
    ui->txtSensorPort4->setText(mcu.SensorPort4);
    ui->txtSensorPort5->setText(mcu.SensorPort5);
    genId();
}

void frmnodeMCU::genId()
{
    int index1 = 0;
    QString id="",id2="";

    if(ui->txtId->text()==""){
        index1=ui->cbonodeMCU->currentIndex()+1;

        //ui->cboTSensor->currentIndex()==0 ? index2=10:index2=20;
        //index2=ui->cboTSensor->currentIndex()+10;
        qDebug()<<"index1 "+QString::number(index1);
        id = "10"+QString::number(index1);
        id = id.mid(id.length()-2);

        ui->txtId->setText(id);
    }
}

void frmnodeMCU::on_cbonodeMCU_currentIndexChanged(int index)
{
    readSettingnodeMCU(index+1);
}
