#include "frmsensor1.h"
#include "ui_frmsensor1.h"

frmsensor1::frmsensor1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmsensor1)
{
    ui->setupUi(this);
    twc = new TimerWaterControl(QApplication::applicationDirPath());
    ui->cboSensor->addItem("Sensor 1", QVariant(1));
    ui->cboSensor->addItem("Sensor 2", QVariant(2));
    ui->cboSensor->addItem("Sensor 3", QVariant(3));
    ui->cboSensor->addItem("Sensor 4", QVariant(4));
    ui->cboSensor->addItem("Sensor 5", QVariant(5));
    ui->cboSensor->addItem("Sensor 6", QVariant(6));
    ui->cboSensor->addItem("Sensor 7", QVariant(7));
    ui->cboSensor->addItem("Sensor 8", QVariant(8));
    ui->cboSensor->addItem("Sensor 9", QVariant(9));
    ui->cboSensor->addItem("Sensor 10", QVariant(10));
    ui->cboSensor->addItem("Sensor 11", QVariant(11));
    ui->cboSensor->addItem("Sensor 12", QVariant(12));
    ui->cboSensor->addItem("Sensor 13", QVariant(13));
    ui->cboSensor->addItem("Sensor 14", QVariant(14));
    ui->cboSensor->addItem("Sensor 15", QVariant(15));
    ui->cboSensor->addItem("Sensor 16", QVariant(16));
    ui->cboSensor->addItem("Sensor 17", QVariant(17));
    ui->cboSensor->addItem("Sensor 18", QVariant(18));
    ui->cboSensor->addItem("Sensor 19", QVariant(19));
    ui->cboSensor->addItem("Sensor 20", QVariant(20));
    ui->cboSensor->addItem("Sensor 21", QVariant(20));
    ui->cboSensor->addItem("Sensor 22", QVariant(20));
    ui->cboSensor->addItem("Sensor 23", QVariant(20));
    ui->cboSensor->addItem("Sensor 24", QVariant(20));
    ui->cboSensor->addItem("Sensor 25", QVariant(20));
    ui->cboSensor->addItem("Sensor 26", QVariant(20));
    ui->cboSensor->addItem("Sensor 27", QVariant(20));
    ui->cboSensor->addItem("Sensor 28", QVariant(20));
    ui->cboSensor->addItem("Sensor 29", QVariant(20));

    ui->cboTSensor->addItem("วัดระยะ หน่วยเป็น cm", QVariant(20));
    ui->cboTSensor->addItem("วัดวามชื่น ในดิน", QVariant(20));

    ui->cboBrand->addItem("Catalex", QVariant(20));
    ui->cboBrand->addItem("JSN", QVariant(20));
    ui->cboBrand->addItem("China Direct", QVariant(20));

    ui->cboModel->addItem("Catalex Moisture Sensor", QVariant(20));
    ui->cboModel->addItem("JSN-SR04T", QVariant(20));
    ui->cboModel->addItem("HC-SR04", QVariant(20));
}

frmsensor1::~frmsensor1()
{
    delete ui;
}

void frmsensor1::writeSettingSensor()
{
    Sensor sen;
    ui->chkactive->isChecked() ? sen.Active="on":sen.Active="off";

    ui->chkStatusFaucetnodeMCU->isChecked() ? sen.StatusFaucetnodeMCU="on":sen.StatusFaucetnodeMCU="off";
    ui->chkStatusPumpnodeMCU->isChecked() ? sen.StatusPumpnodeMCU="on":sen.StatusPumpnodeMCU="off";

    //ui->chkRainrelayON->isChecked() ? tim.RainrelayON="on":tim.RainrelayON="off";
    //int index = ui->cboBrand->findText(value);
    //if ( index != -1 ) { // -1 for not found
    //   combo->setCurrentIndex(index);
    //}


    sen.Brand = ui->cboBrand->currentText();
    sen.Description = ui->txtDesc->text();
    sen.Id = ui->txtId->text();
    sen.Max1 = QString::number(ui->doubleSpinBoxMax->value());
    sen.Min1 = QString::number(ui->doubleSpinBoxMin->value());
    sen.Model = ui->cboModel->currentText();
    sen.TSensor = ui->cboTSensor->currentText();

    sen.IPFaucetnodeMCU = ui->txtIPFaucetnodeMCU->text();
    sen.IPnodeMCU = ui->txtIPnodeMCU->text();
    sen.IPPumpnodeMCU = ui->txtIPPumpnodeMCU->text();
    sen.PortFaucet = ui->txtPort->text();
    sen.PortPump = ui->txtPortPump->text();
    sen.PortSensor = ui->txtPortSensor->text();

    twc->writeSettingSensor((ui->cboSensor->currentIndex()+1),sen);
}

void frmsensor1::readSettingSensor(int row)
{
    Sensor sen;
    sen = twc->readSettingSensor(row);
    qDebug()<<"active "+sen.Active;

    sen.Active=="1" ? ui->chkactive->setChecked(true):ui->chkactive->setChecked(false);
    sen.Active=="0" ? ui->chkUnActive->setChecked(true):ui->chkUnActive->setChecked(false);
    sen.StatusFaucetnodeMCU=="1" ? ui->chkStatusFaucetnodeMCU->setChecked(true):ui->chkStatusFaucetnodeMCU->setChecked(false);
    sen.StatusPumpnodeMCU=="1" ? ui->chkStatusPumpnodeMCU->setChecked(true):ui->chkStatusPumpnodeMCU->setChecked(false);

    int index = ui->cboBrand->findText(sen.Brand);
    if ( index != -1 ) { // -1 for not found
       ui->cboBrand->setCurrentIndex(index);
    }
    index = ui->cboModel->findText(sen.Model);
    if ( index != -1 ) { // -1 for not found
       ui->cboModel->setCurrentIndex(index);
    }
    index = ui->cboTSensor->findText(sen.TSensor);
    if ( index != -1 ) { // -1 for not found
       ui->cboTSensor->setCurrentIndex(index);
    }
    ui->txtId->setText(sen.Id);

    ui->doubleSpinBoxMax->setValue(sen.Max1.toInt());
    ui->doubleSpinBoxMin->setValue(sen.Min1.toInt());
    //ui->txtTrigerPort->setText(tim.TriggerPort);
    ui->txtDesc->setText(sen.Description);

    ui->chkStatusFaucetnodeMCU->isChecked() ? ui->txtIPFaucetnodeMCU->setVisible(true):ui->txtIPFaucetnodeMCU->setVisible(false);
    ui->chkStatusPumpnodeMCU->isChecked() ? ui->txtIPPumpnodeMCU->setVisible(true):ui->txtIPPumpnodeMCU->setVisible(false);

    ui->txtIPFaucetnodeMCU->setText(sen.IPFaucetnodeMCU);
    ui->txtIPPumpnodeMCU->setText(sen.IPPumpnodeMCU);
    ui->txtPortPump->setText(sen.PortPump);
    ui->txtPort->setText(sen.PortFaucet);
    ui->txtPortSensor->setText(sen.PortSensor);
    ui->txtIPnodeMCU->setText(sen.IPnodeMCU);
    sen.Id=="" ? isNew=true:isNew=false;
}

void frmsensor1::genId()
{
    int index1 = 0, index2=0;
    QString id="",id2="";

    if(isNew){
        index1=ui->cboSensor->currentIndex()+1;

        ui->cboTSensor->currentIndex()==0 ? index2=10:index2=20;
        //index2=ui->cboTSensor->currentIndex()+10;
        qDebug()<<"index1 "+QString::number(index1);
        id = "000"+QString::number(index1);
        id = id.mid(id.length()-3);
        //id2 = QString::number(index2);
        //id2 = id2.mid(id2.length()-3);
        id = QString::number(index2)+id;
        ui->txtId->setText(id);
    }
}

void frmsensor1::on_btnSave_clicked()
{
    writeSettingSensor();
}

void frmsensor1::on_cboSensor_currentIndexChanged(int index)
{
    readSettingSensor(index+1);
    genId();
}

void frmsensor1::on_cboTSensor_currentIndexChanged(int index)
{
    genId();
}

void frmsensor1::on_chkStatusPumpnodeMCU_clicked(bool checked)
{
    ui->chkStatusPumpnodeMCU->isChecked() ? ui->txtIPPumpnodeMCU->setVisible(true):ui->txtIPPumpnodeMCU->setVisible(false);
}

void frmsensor1::on_chkStatusFaucetnodeMCU_clicked(bool checked)
{
    ui->chkStatusFaucetnodeMCU->isChecked() ? ui->txtIPFaucetnodeMCU->setVisible(true):ui->txtIPFaucetnodeMCU->setVisible(false);
}
