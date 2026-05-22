/*
    Copyright 2016-2026 melonDS team

    This file is part of melonDS.

    melonDS is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    melonDS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with melonDS. If not, see http://www.gnu.org/licenses/.
*/

#include <QStyleFactory>
#include <QKeyEvent>
#include "InterfaceSettingsDialog.h"
#include "ui_InterfaceSettingsDialog.h"

#include "types.h"
#include "Platform.h"
#include "Config.h"
#include "main.h"
#include "Language.h"
#include "Window.h"

InterfaceSettingsDialog* InterfaceSettingsDialog::currentDlg = nullptr;
InterfaceSettingsDialog::InterfaceSettingsDialog(QWidget* parent) : QDialog(parent), ui(new Ui::InterfaceSettingsDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    emuInstance = ((MainWindow*)parent)->getEmuInstance();

    auto& cfg = emuInstance->getGlobalConfig();

    // Language setting
    ui->cbxLanguage->addItem("English", "");
    ui->cbxLanguage->addItem("简体中文", "zh-CN");

    QString cfgLang = cfg.GetQString("Language");
    if (cfgLang == "zh-CN")
        ui->cbxLanguage->setCurrentIndex(1);

    // Boss key setting
    int bossKeyCode = cfg.GetInt("BossKey");
    if (bossKeyCode > 0)
    {
        ui->pbBossKey->setText(QKeySequence(bossKeyCode).toString());
    }
    else
    {
        ui->pbBossKey->setText("None");
    }

    ui->cbMouseHide->setChecked(cfg.GetBool("Mouse.Hide"));
    ui->spinMouseHideSeconds->setEnabled(ui->cbMouseHide->isChecked());
    ui->spinMouseHideSeconds->setValue(cfg.GetInt("Mouse.HideSeconds"));
    ui->cbPauseLostFocus->setChecked(cfg.GetBool("PauseLostFocus"));
    ui->cbMuteFastForward->setChecked(cfg.GetBool("MuteFastForward"));
    ui->spinTargetFPS->setValue(cfg.GetDouble("TargetFPS"));
    ui->spinFFW->setValue(cfg.GetDouble("FastForwardFPS"));
    ui->spinSlow->setValue(cfg.GetDouble("SlowmoFPS"));

    const QList<QString> themeKeys = QStyleFactory::keys();
    const QString currentTheme = qApp->style()->objectName();
    QString cfgTheme = cfg.GetQString("UITheme");

    ui->cbxUITheme->addItem("System default", "");

    for (int i = 0; i < themeKeys.length(); i++)
    {
        ui->cbxUITheme->addItem(themeKeys[i], themeKeys[i]);
        if (!cfgTheme.isEmpty() && themeKeys[i].compare(currentTheme, Qt::CaseInsensitive) == 0)
            ui->cbxUITheme->setCurrentIndex(i + 1);
    }

    // Translate all UI labels using LTr()
    setWindowTitle(LTr("Interface settings - melonDS"));
    ui->groupBox_Language->setTitle(LTr("Language"));
    ui->label_Language->setText(LTr("Language"));
    ui->groupBox_BossKey->setTitle(LTr("Boss Key"));
    ui->label_BossKey->setText(LTr("Boss key (press to hide/show window)"));
    ui->pbBossKey->setText(LTr("Press a key"));
    ui->groupBox->setTitle(LTr("User interface"));
    ui->label_4->setText(LTr("Theme"));
    ui->cbMouseHide->setText(LTr("Hide mouse after inactivity"));
    ui->label->setText(LTr("After"));
    ui->label_2->setText(LTr("seconds"));
    ui->cbPauseLostFocus->setText(LTr("Pause emulation when window is not in focus"));
    ui->cbMuteFastForward->setText(LTr("Mute audio while fast forwarding"));
    ui->groupBox_2->setTitle(LTr("Framerate"));
    ui->label_5->setText(LTr("Target FPS"));
    ui->label_3->setText(LTr("Fast-Forward"));
    ui->label_6->setText(LTr("Slow-Mo"));
    ui->pbAccurate->setText(LTr("Accurate"));
    ui->pbClean->setText(LTr("Clean"));
    ui->pb2x->setText(LTr("2x"));
    ui->pb3x->setText(LTr("3x"));
    ui->pbMAX->setText(LTr("MAX"));
    ui->pbQuarter->setText(LTr("1/4"));
    ui->pbHalf->setText(LTr("1/2"));

    // Re-set boss key text from config (overrides the LTr above if a key is set)
    if (bossKeyCode > 0)
    {
        ui->pbBossKey->setText(QKeySequence(bossKeyCode).toString());
    }
}

InterfaceSettingsDialog::~InterfaceSettingsDialog()
{
    delete ui;
}

void InterfaceSettingsDialog::keyPressEvent(QKeyEvent* event)
{
    if (waitingForBossKey)
    {
        int key = event->key();
        // Ignore modifier-only keys
        if (key != Qt::Key_Shift && key != Qt::Key_Control && key != Qt::Key_Alt && key != Qt::Key_Meta)
        {
            int modifiers = event->modifiers() & (Qt::ShiftModifier | Qt::ControlModifier | Qt::AltModifier | Qt::MetaModifier);
            int combined = key | modifiers;
            ui->pbBossKey->setText(QKeySequence(combined).toString());
            waitingForBossKey = false;
        }
        return;
    }

    QDialog::keyPressEvent(event);
}

void InterfaceSettingsDialog::on_cbMouseHide_clicked()
{
    ui->spinMouseHideSeconds->setEnabled(ui->cbMouseHide->isChecked());
}

void InterfaceSettingsDialog::on_pbBossKey_clicked()
{
    if (waitingForBossKey)
    {
        // Cancel - reset to previous value
        waitingForBossKey = false;
        auto& cfg = emuInstance->getGlobalConfig();
        int bossKeyCode = cfg.GetInt("BossKey");
        if (bossKeyCode > 0)
            ui->pbBossKey->setText(QKeySequence(bossKeyCode).toString());
        else
            ui->pbBossKey->setText("None");
    }
    else
    {
        waitingForBossKey = true;
        ui->pbBossKey->setText("Press a key...");
    }
}

void InterfaceSettingsDialog::on_pbClean_clicked()
{
    ui->spinTargetFPS->setValue(60.0000);
}

void InterfaceSettingsDialog::on_pbAccurate_clicked()
{
    ui->spinTargetFPS->setValue(59.8261);
}

void InterfaceSettingsDialog::on_pb2x_clicked()
{
    ui->spinFFW->setValue(ui->spinTargetFPS->value() * 2.0);
}

void InterfaceSettingsDialog::on_pb3x_clicked()
{
    ui->spinFFW->setValue(ui->spinTargetFPS->value() * 3.0);
}

void InterfaceSettingsDialog::on_pbMAX_clicked()
{
    ui->spinFFW->setValue(1000.0);
}

void InterfaceSettingsDialog::on_pbHalf_clicked()
{
    ui->spinSlow->setValue(ui->spinTargetFPS->value() / 2.0);
}

void InterfaceSettingsDialog::on_pbQuarter_clicked()
{
    ui->spinSlow->setValue(ui->spinTargetFPS->value() / 4.0);
}

void InterfaceSettingsDialog::done(int r)
{
    if (!((MainWindow*)parent())->getEmuInstance())
    {
        QDialog::done(r);
        closeDlg();
        return;
    }

    if (r == QDialog::Accepted)
    {
        auto& cfg = emuInstance->getGlobalConfig();

        // Language
        QString lang = ui->cbxLanguage->currentData().toString();
        cfg.SetQString("Language", lang);
        Language::isChinese = (lang == "zh-CN");

        // Boss key
        QString bossText = ui->pbBossKey->text();
        if (bossText == "None" || bossText == "Press a key...")
        {
            cfg.SetInt("BossKey", 0);
        }
        else
        {
            QKeySequence seq = QKeySequence::fromString(bossText);
            if (!seq.isEmpty())
                cfg.SetInt("BossKey", seq[0].toCombined());
        }

        cfg.SetBool("Mouse.Hide", ui->cbMouseHide->isChecked());
        cfg.SetInt("Mouse.HideSeconds", ui->spinMouseHideSeconds->value());
        cfg.SetBool("PauseLostFocus", ui->cbPauseLostFocus->isChecked());
        cfg.SetBool("MuteFastForward", ui->cbMuteFastForward->isChecked());

        double val = ui->spinTargetFPS->value();
        if (val == 0.0) cfg.SetDouble("TargetFPS", 0.0001);
        else cfg.SetDouble("TargetFPS", val);
        
        val = ui->spinFFW->value();
        if (val == 0.0) cfg.SetDouble("FastForwardFPS", 0.0001);
        else cfg.SetDouble("FastForwardFPS", val);
        
        val = ui->spinSlow->value();
        if (val == 0.0) cfg.SetDouble("SlowmoFPS", 0.0001);
        else cfg.SetDouble("SlowmoFPS", val);

        QString themeName = ui->cbxUITheme->currentData().toString();
        cfg.SetQString("UITheme", themeName);

        Config::Save();

        if (!themeName.isEmpty())
            qApp->setStyle(themeName);
        else
            qApp->setStyle(*systemThemeName);

        emit updateInterfaceSettings();
    }

    QDialog::done(r);
    closeDlg();
}
