/********************************************************************************
** Form generated from reading UI file 'design.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGN_H
#define DESIGN_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_11;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_15;
    QFrame *move_label;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *y_box;
    QLabel *label;
    QPushButton *rotate_btn;
    QDoubleSpinBox *x_box;
    QPushButton *move_btn;
    QDoubleSpinBox *z_box;
    QLabel *label_2;
    QPushButton *scale_btn;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QDoubleSpinBox *refr_idx_box;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *alb0_box;
    QDoubleSpinBox *alb1_box;
    QDoubleSpinBox *alb2_box;
    QDoubleSpinBox *alb3_box;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_15;
    QDoubleSpinBox *diff_color0_box;
    QDoubleSpinBox *diff_color2_box;
    QDoubleSpinBox *diff_color1_box;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_16;
    QDoubleSpinBox *spec_exp_box;
    QPushButton *stuuub;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_17;
    QDoubleSpinBox *intensity_box;
    QListWidget *lights_list;
    QVBoxLayout *verticalLayout_2;
    QPushButton *add_light_btn;
    QPushButton *load_light_btn;
    QPushButton *stub;
    QPushButton *rm_light_btn;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLabel *curr_camera_lbl;
    QListWidget *cams_list;
    QPushButton *add_camera_btn;
    QPushButton *change_camera_btn;
    QPushButton *rm_cam_btn;
    QVBoxLayout *verticalLayout;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QLabel *curr_model_lbl;
    QListWidget *models_list;
    QPushButton *load_model_btn;
    QPushButton *change_model_btn;
    QPushButton *rm_mod_btn;
    QPushButton *load_light_btn_3;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_10;
    QLabel *curr_loc_lbl;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_12;
    QPushButton *left_btn;
    QPushButton *right_btn;
    QVBoxLayout *verticalLayout_11;
    QPushButton *up_btn;
    QPushButton *down_btn;
    QVBoxLayout *verticalLayout_10;
    QPushButton *zoom_in_btn;
    QPushButton *zoom_out_btn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 950);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1600, 950));
        MainWindow->setMaximumSize(QSize(1600, 950));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(114, 159, 207, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(220, 222, 218, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(93, 94, 91, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(124, 126, 121, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush6(QColor(186, 189, 182, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setToolTipDuration(12);
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_11 = new QHBoxLayout(centralwidget);
        horizontalLayout_11->setSpacing(5);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, -1, 2);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(9);
        graphicsView->setFont(font);

        horizontalLayout_11->addWidget(graphicsView);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(15);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        move_label = new QFrame(centralwidget);
        move_label->setObjectName(QString::fromUtf8("move_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(move_label->sizePolicy().hasHeightForWidth());
        move_label->setSizePolicy(sizePolicy1);
        move_label->setFont(font);
        move_label->setFrameShape(QFrame::StyledPanel);
        move_label->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(move_label);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        y_box = new QDoubleSpinBox(move_label);
        y_box->setObjectName(QString::fromUtf8("y_box"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(11);
        y_box->setFont(font1);
        y_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        y_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        y_box->setMinimum(-10000000000000000000000.000000000000000);
        y_box->setMaximum(10000000000000000000000.000000000000000);

        gridLayout_5->addWidget(y_box, 1, 1, 1, 1);

        label = new QLabel(move_label);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Lucida Console"));
        font2.setPointSize(11);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        rotate_btn = new QPushButton(move_label);
        rotate_btn->setObjectName(QString::fromUtf8("rotate_btn"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush9(QColor(127, 30, 207, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush10(QColor(182, 92, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush10);
        QBrush brush11(QColor(154, 61, 231, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        QBrush brush12(QColor(63, 15, 103, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush12);
        QBrush brush13(QColor(85, 20, 138, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush14(QColor(191, 142, 231, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        rotate_btn->setPalette(palette1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font3.setPointSize(12);
        rotate_btn->setFont(font3);

        gridLayout_5->addWidget(rotate_btn, 2, 2, 1, 1);

        x_box = new QDoubleSpinBox(move_label);
        x_box->setObjectName(QString::fromUtf8("x_box"));
        x_box->setMinimumSize(QSize(0, 1));
        x_box->setFont(font1);
        x_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        x_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        x_box->setMinimum(-10000000000000000.000000000000000);
        x_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_5->addWidget(x_box, 0, 1, 1, 1);

        move_btn = new QPushButton(move_label);
        move_btn->setObjectName(QString::fromUtf8("move_btn"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        move_btn->setPalette(palette2);
        move_btn->setFont(font3);

        gridLayout_5->addWidget(move_btn, 1, 2, 1, 1);

        z_box = new QDoubleSpinBox(move_label);
        z_box->setObjectName(QString::fromUtf8("z_box"));
        z_box->setFont(font1);
        z_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        z_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        z_box->setMinimum(-99999999999999991611392.000000000000000);
        z_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_5->addWidget(z_box, 2, 1, 1, 1);

        label_2 = new QLabel(move_label);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_2, 1, 0, 1, 1);

        scale_btn = new QPushButton(move_label);
        scale_btn->setObjectName(QString::fromUtf8("scale_btn"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        scale_btn->setPalette(palette3);
        scale_btn->setFont(font3);

        gridLayout_5->addWidget(scale_btn, 0, 2, 1, 1);

        label_3 = new QLabel(move_label);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_3, 2, 0, 1, 1);


        verticalLayout_15->addWidget(move_label);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);
        label_18->setMinimumSize(QSize(0, 15));
        label_18->setMaximumSize(QSize(16777215, 15));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial Black"));
        font4.setPointSize(8);
        label_18->setFont(font4);
        label_18->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_18);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(0, 15));
        label_11->setMaximumSize(QSize(16777215, 15));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font5.setPointSize(12);
        font5.setBold(false);
        font5.setWeight(50);
        label_11->setFont(font5);
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_11);

        refr_idx_box = new QDoubleSpinBox(centralwidget);
        refr_idx_box->setObjectName(QString::fromUtf8("refr_idx_box"));
        sizePolicy.setHeightForWidth(refr_idx_box->sizePolicy().hasHeightForWidth());
        refr_idx_box->setSizePolicy(sizePolicy);
        refr_idx_box->setMinimumSize(QSize(42, 22));
        refr_idx_box->setMaximumSize(QSize(40, 20));
        refr_idx_box->setFont(font1);
        refr_idx_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        refr_idx_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        refr_idx_box->setMinimum(-10000000000000000.000000000000000);
        refr_idx_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_5->addWidget(refr_idx_box);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setMinimumSize(QSize(0, 15));
        label_12->setMaximumSize(QSize(16777215, 15));
        label_12->setFont(font5);
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_12);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        alb0_box = new QDoubleSpinBox(centralwidget);
        alb0_box->setObjectName(QString::fromUtf8("alb0_box"));
        sizePolicy.setHeightForWidth(alb0_box->sizePolicy().hasHeightForWidth());
        alb0_box->setSizePolicy(sizePolicy);
        alb0_box->setMinimumSize(QSize(42, 22));
        alb0_box->setMaximumSize(QSize(40, 20));
        alb0_box->setFont(font1);
        alb0_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        alb0_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alb0_box->setMinimum(-10000000000000000.000000000000000);
        alb0_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_3->addWidget(alb0_box);

        alb1_box = new QDoubleSpinBox(centralwidget);
        alb1_box->setObjectName(QString::fromUtf8("alb1_box"));
        sizePolicy.setHeightForWidth(alb1_box->sizePolicy().hasHeightForWidth());
        alb1_box->setSizePolicy(sizePolicy);
        alb1_box->setMinimumSize(QSize(42, 22));
        alb1_box->setMaximumSize(QSize(40, 20));
        alb1_box->setFont(font1);
        alb1_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        alb1_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alb1_box->setMinimum(-10000000000000000.000000000000000);
        alb1_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_3->addWidget(alb1_box);

        alb2_box = new QDoubleSpinBox(centralwidget);
        alb2_box->setObjectName(QString::fromUtf8("alb2_box"));
        sizePolicy.setHeightForWidth(alb2_box->sizePolicy().hasHeightForWidth());
        alb2_box->setSizePolicy(sizePolicy);
        alb2_box->setMinimumSize(QSize(42, 22));
        alb2_box->setMaximumSize(QSize(40, 20));
        alb2_box->setFont(font1);
        alb2_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        alb2_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alb2_box->setMinimum(-10000000000000000.000000000000000);
        alb2_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_3->addWidget(alb2_box);

        alb3_box = new QDoubleSpinBox(centralwidget);
        alb3_box->setObjectName(QString::fromUtf8("alb3_box"));
        sizePolicy.setHeightForWidth(alb3_box->sizePolicy().hasHeightForWidth());
        alb3_box->setSizePolicy(sizePolicy);
        alb3_box->setMinimumSize(QSize(42, 22));
        alb3_box->setMaximumSize(QSize(40, 20));
        alb3_box->setFont(font1);
        alb3_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        alb3_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alb3_box->setMinimum(-10000000000000000.000000000000000);
        alb3_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_3->addWidget(alb3_box);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setMinimumSize(QSize(0, 15));
        label_15->setMaximumSize(QSize(16777215, 15));
        label_15->setFont(font5);
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_15);

        diff_color0_box = new QDoubleSpinBox(centralwidget);
        diff_color0_box->setObjectName(QString::fromUtf8("diff_color0_box"));
        sizePolicy.setHeightForWidth(diff_color0_box->sizePolicy().hasHeightForWidth());
        diff_color0_box->setSizePolicy(sizePolicy);
        diff_color0_box->setMinimumSize(QSize(42, 22));
        diff_color0_box->setMaximumSize(QSize(40, 20));
        diff_color0_box->setFont(font1);
        diff_color0_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        diff_color0_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        diff_color0_box->setMinimum(-10000000000000000.000000000000000);
        diff_color0_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_6->addWidget(diff_color0_box);

        diff_color2_box = new QDoubleSpinBox(centralwidget);
        diff_color2_box->setObjectName(QString::fromUtf8("diff_color2_box"));
        sizePolicy.setHeightForWidth(diff_color2_box->sizePolicy().hasHeightForWidth());
        diff_color2_box->setSizePolicy(sizePolicy);
        diff_color2_box->setMinimumSize(QSize(42, 22));
        diff_color2_box->setMaximumSize(QSize(40, 20));
        diff_color2_box->setFont(font1);
        diff_color2_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        diff_color2_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        diff_color2_box->setMinimum(-10000000000000000.000000000000000);
        diff_color2_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_6->addWidget(diff_color2_box);

        diff_color1_box = new QDoubleSpinBox(centralwidget);
        diff_color1_box->setObjectName(QString::fromUtf8("diff_color1_box"));
        sizePolicy.setHeightForWidth(diff_color1_box->sizePolicy().hasHeightForWidth());
        diff_color1_box->setSizePolicy(sizePolicy);
        diff_color1_box->setMinimumSize(QSize(42, 22));
        diff_color1_box->setMaximumSize(QSize(40, 20));
        diff_color1_box->setFont(font1);
        diff_color1_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        diff_color1_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        diff_color1_box->setMinimum(-10000000000000000.000000000000000);
        diff_color1_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_6->addWidget(diff_color1_box);


        verticalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);
        label_16->setMinimumSize(QSize(0, 15));
        label_16->setMaximumSize(QSize(16777215, 15));
        label_16->setFont(font5);
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_16);

        spec_exp_box = new QDoubleSpinBox(centralwidget);
        spec_exp_box->setObjectName(QString::fromUtf8("spec_exp_box"));
        sizePolicy.setHeightForWidth(spec_exp_box->sizePolicy().hasHeightForWidth());
        spec_exp_box->setSizePolicy(sizePolicy);
        spec_exp_box->setMinimumSize(QSize(42, 22));
        spec_exp_box->setMaximumSize(QSize(40, 20));
        spec_exp_box->setFont(font1);
        spec_exp_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        spec_exp_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spec_exp_box->setMinimum(-10000000000000000.000000000000000);
        spec_exp_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_7->addWidget(spec_exp_box);


        verticalLayout_7->addLayout(horizontalLayout_7);


        verticalLayout_8->addLayout(verticalLayout_7);


        verticalLayout_4->addLayout(verticalLayout_8);

        stuuub = new QPushButton(centralwidget);
        stuuub->setObjectName(QString::fromUtf8("stuuub"));
        sizePolicy.setHeightForWidth(stuuub->sizePolicy().hasHeightForWidth());
        stuuub->setSizePolicy(sizePolicy);
        stuuub->setMinimumSize(QSize(140, 30));
        stuuub->setMaximumSize(QSize(140, 30));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        stuuub->setPalette(palette4);
        QFont font6;
        font6.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font6.setPointSize(11);
        stuuub->setFont(font6);

        verticalLayout_4->addWidget(stuuub);


        verticalLayout_15->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);
        label_14->setMinimumSize(QSize(0, 15));
        label_14->setMaximumSize(QSize(16777215, 15));
        label_14->setFont(font4);
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_14);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);
        label_17->setMinimumSize(QSize(0, 15));
        label_17->setMaximumSize(QSize(16777215, 15));
        label_17->setFont(font5);
        label_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_17);

        intensity_box = new QDoubleSpinBox(centralwidget);
        intensity_box->setObjectName(QString::fromUtf8("intensity_box"));
        sizePolicy.setHeightForWidth(intensity_box->sizePolicy().hasHeightForWidth());
        intensity_box->setSizePolicy(sizePolicy);
        intensity_box->setMinimumSize(QSize(42, 22));
        intensity_box->setMaximumSize(QSize(40, 20));
        intensity_box->setFont(font1);
        intensity_box->setLocale(QLocale(QLocale::English, QLocale::Canada));
        intensity_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        intensity_box->setMinimum(-10000000000000000.000000000000000);
        intensity_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_10->addWidget(intensity_box);


        verticalLayout_3->addLayout(horizontalLayout_10);

        lights_list = new QListWidget(centralwidget);
        lights_list->setObjectName(QString::fromUtf8("lights_list"));
        sizePolicy.setHeightForWidth(lights_list->sizePolicy().hasHeightForWidth());
        lights_list->setSizePolicy(sizePolicy);
        lights_list->setMinimumSize(QSize(145, 77));
        lights_list->setMaximumSize(QSize(150, 50));

        verticalLayout_3->addWidget(lights_list);


        horizontalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        add_light_btn = new QPushButton(centralwidget);
        add_light_btn->setObjectName(QString::fromUtf8("add_light_btn"));
        sizePolicy.setHeightForWidth(add_light_btn->sizePolicy().hasHeightForWidth());
        add_light_btn->setSizePolicy(sizePolicy);
        add_light_btn->setMinimumSize(QSize(140, 30));
        add_light_btn->setMaximumSize(QSize(140, 30));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        add_light_btn->setPalette(palette5);
        add_light_btn->setFont(font6);

        verticalLayout_2->addWidget(add_light_btn);

        load_light_btn = new QPushButton(centralwidget);
        load_light_btn->setObjectName(QString::fromUtf8("load_light_btn"));
        sizePolicy.setHeightForWidth(load_light_btn->sizePolicy().hasHeightForWidth());
        load_light_btn->setSizePolicy(sizePolicy);
        load_light_btn->setMinimumSize(QSize(140, 30));
        load_light_btn->setMaximumSize(QSize(140, 30));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        load_light_btn->setPalette(palette6);
        load_light_btn->setFont(font6);

        verticalLayout_2->addWidget(load_light_btn);

        stub = new QPushButton(centralwidget);
        stub->setObjectName(QString::fromUtf8("stub"));
        sizePolicy.setHeightForWidth(stub->sizePolicy().hasHeightForWidth());
        stub->setSizePolicy(sizePolicy);
        stub->setMinimumSize(QSize(140, 30));
        stub->setMaximumSize(QSize(140, 30));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        stub->setPalette(palette7);
        stub->setFont(font6);

        verticalLayout_2->addWidget(stub);

        rm_light_btn = new QPushButton(centralwidget);
        rm_light_btn->setObjectName(QString::fromUtf8("rm_light_btn"));
        sizePolicy.setHeightForWidth(rm_light_btn->sizePolicy().hasHeightForWidth());
        rm_light_btn->setSizePolicy(sizePolicy);
        rm_light_btn->setMinimumSize(QSize(140, 30));
        rm_light_btn->setMaximumSize(QSize(140, 30));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        rm_light_btn->setPalette(palette8);
        rm_light_btn->setFont(font6);

        verticalLayout_2->addWidget(rm_light_btn);


        horizontalLayout_8->addLayout(verticalLayout_2);


        verticalLayout_6->addLayout(horizontalLayout_8);


        verticalLayout_15->addLayout(verticalLayout_6);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, -1, -1, -1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setMinimumSize(QSize(0, 15));
        label_7->setMaximumSize(QSize(16777215, 15));
        label_7->setFont(font4);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(0, 15));
        label_8->setMaximumSize(QSize(16777215, 15));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font7.setPointSize(11);
        font7.setBold(false);
        font7.setWeight(50);
        label_8->setFont(font7);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_8);

        curr_camera_lbl = new QLabel(centralwidget);
        curr_camera_lbl->setObjectName(QString::fromUtf8("curr_camera_lbl"));
        sizePolicy1.setHeightForWidth(curr_camera_lbl->sizePolicy().hasHeightForWidth());
        curr_camera_lbl->setSizePolicy(sizePolicy1);
        curr_camera_lbl->setMinimumSize(QSize(0, 15));
        curr_camera_lbl->setMaximumSize(QSize(16777215, 15));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font8.setPointSize(11);
        font8.setBold(true);
        font8.setWeight(75);
        curr_camera_lbl->setFont(font8);
        curr_camera_lbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(curr_camera_lbl);


        verticalLayout_5->addLayout(horizontalLayout_2);

        cams_list = new QListWidget(centralwidget);
        cams_list->setObjectName(QString::fromUtf8("cams_list"));
        sizePolicy.setHeightForWidth(cams_list->sizePolicy().hasHeightForWidth());
        cams_list->setSizePolicy(sizePolicy);
        cams_list->setMinimumSize(QSize(145, 50));
        cams_list->setMaximumSize(QSize(150, 50));

        verticalLayout_5->addWidget(cams_list);

        add_camera_btn = new QPushButton(centralwidget);
        add_camera_btn->setObjectName(QString::fromUtf8("add_camera_btn"));
        sizePolicy.setHeightForWidth(add_camera_btn->sizePolicy().hasHeightForWidth());
        add_camera_btn->setSizePolicy(sizePolicy);
        add_camera_btn->setMinimumSize(QSize(140, 30));
        add_camera_btn->setMaximumSize(QSize(140, 30));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        add_camera_btn->setPalette(palette9);
        add_camera_btn->setFont(font6);

        verticalLayout_5->addWidget(add_camera_btn);

        change_camera_btn = new QPushButton(centralwidget);
        change_camera_btn->setObjectName(QString::fromUtf8("change_camera_btn"));
        sizePolicy.setHeightForWidth(change_camera_btn->sizePolicy().hasHeightForWidth());
        change_camera_btn->setSizePolicy(sizePolicy);
        change_camera_btn->setMinimumSize(QSize(140, 30));
        change_camera_btn->setMaximumSize(QSize(140, 30));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette10.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette10.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette10.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette10.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        change_camera_btn->setPalette(palette10);
        change_camera_btn->setFont(font6);

        verticalLayout_5->addWidget(change_camera_btn);

        rm_cam_btn = new QPushButton(centralwidget);
        rm_cam_btn->setObjectName(QString::fromUtf8("rm_cam_btn"));
        sizePolicy.setHeightForWidth(rm_cam_btn->sizePolicy().hasHeightForWidth());
        rm_cam_btn->setSizePolicy(sizePolicy);
        rm_cam_btn->setMinimumSize(QSize(140, 30));
        rm_cam_btn->setMaximumSize(QSize(140, 30));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette11.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette11.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette11.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette11.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush);
        palette11.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette11.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette11.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette11.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette11.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette11.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        rm_cam_btn->setPalette(palette11);
        rm_cam_btn->setFont(font6);

        verticalLayout_5->addWidget(rm_cam_btn);


        horizontalLayout_9->addLayout(verticalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);
        label_13->setMinimumSize(QSize(0, 15));
        label_13->setMaximumSize(QSize(16777215, 15));
        label_13->setFont(font4);
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_13);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(0, 15));
        label_9->setMaximumSize(QSize(16777215, 15));
        label_9->setFont(font7);
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_9);

        curr_model_lbl = new QLabel(centralwidget);
        curr_model_lbl->setObjectName(QString::fromUtf8("curr_model_lbl"));
        sizePolicy1.setHeightForWidth(curr_model_lbl->sizePolicy().hasHeightForWidth());
        curr_model_lbl->setSizePolicy(sizePolicy1);
        curr_model_lbl->setMinimumSize(QSize(0, 15));
        curr_model_lbl->setMaximumSize(QSize(16777215, 15));
        curr_model_lbl->setFont(font8);
        curr_model_lbl->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(curr_model_lbl);


        verticalLayout->addLayout(horizontalLayout);

        models_list = new QListWidget(centralwidget);
        models_list->setObjectName(QString::fromUtf8("models_list"));
        sizePolicy.setHeightForWidth(models_list->sizePolicy().hasHeightForWidth());
        models_list->setSizePolicy(sizePolicy);
        models_list->setMinimumSize(QSize(145, 50));
        models_list->setMaximumSize(QSize(150, 50));

        verticalLayout->addWidget(models_list);

        load_model_btn = new QPushButton(centralwidget);
        load_model_btn->setObjectName(QString::fromUtf8("load_model_btn"));
        sizePolicy.setHeightForWidth(load_model_btn->sizePolicy().hasHeightForWidth());
        load_model_btn->setSizePolicy(sizePolicy);
        load_model_btn->setMinimumSize(QSize(140, 30));
        load_model_btn->setMaximumSize(QSize(140, 30));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette12.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette12.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette12.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette12.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette12.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette12.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette12.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette12.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette12.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette12.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette12.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        load_model_btn->setPalette(palette12);
        load_model_btn->setFont(font6);

        verticalLayout->addWidget(load_model_btn);

        change_model_btn = new QPushButton(centralwidget);
        change_model_btn->setObjectName(QString::fromUtf8("change_model_btn"));
        sizePolicy.setHeightForWidth(change_model_btn->sizePolicy().hasHeightForWidth());
        change_model_btn->setSizePolicy(sizePolicy);
        change_model_btn->setMinimumSize(QSize(140, 30));
        change_model_btn->setMaximumSize(QSize(140, 30));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette13.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette13.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette13.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette13.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette13.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette13.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette13.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette13.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette13.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette13.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette13.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        change_model_btn->setPalette(palette13);
        change_model_btn->setFont(font6);

        verticalLayout->addWidget(change_model_btn);

        rm_mod_btn = new QPushButton(centralwidget);
        rm_mod_btn->setObjectName(QString::fromUtf8("rm_mod_btn"));
        sizePolicy.setHeightForWidth(rm_mod_btn->sizePolicy().hasHeightForWidth());
        rm_mod_btn->setSizePolicy(sizePolicy);
        rm_mod_btn->setMinimumSize(QSize(140, 30));
        rm_mod_btn->setMaximumSize(QSize(140, 30));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette14.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette14.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette14.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette14.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush);
        palette14.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette14.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette14.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette14.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette14.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette14.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette14.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette14.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette14.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette14.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette14.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette14.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette14.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        rm_mod_btn->setPalette(palette14);
        rm_mod_btn->setFont(font6);

        verticalLayout->addWidget(rm_mod_btn);


        horizontalLayout_9->addLayout(verticalLayout);


        verticalLayout_9->addLayout(horizontalLayout_9);


        verticalLayout_14->addLayout(verticalLayout_9);


        verticalLayout_15->addLayout(verticalLayout_14);

        load_light_btn_3 = new QPushButton(centralwidget);
        load_light_btn_3->setObjectName(QString::fromUtf8("load_light_btn_3"));
        sizePolicy2.setHeightForWidth(load_light_btn_3->sizePolicy().hasHeightForWidth());
        load_light_btn_3->setSizePolicy(sizePolicy2);
        load_light_btn_3->setMaximumSize(QSize(310, 30));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette15.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette15.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette15.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette15.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush);
        palette15.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette15.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette15.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette15.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette15.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette15.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette15.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette15.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette15.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette15.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette15.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette15.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette15.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette15.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette15.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette15.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette15.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette15.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette15.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette15.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        load_light_btn_3->setPalette(palette15);
        load_light_btn_3->setFont(font6);

        verticalLayout_15->addWidget(load_light_btn_3);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(0, 15));
        label_10->setMaximumSize(QSize(16777215, 15));
        label_10->setFont(font7);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_10);

        curr_loc_lbl = new QLabel(centralwidget);
        curr_loc_lbl->setObjectName(QString::fromUtf8("curr_loc_lbl"));
        sizePolicy1.setHeightForWidth(curr_loc_lbl->sizePolicy().hasHeightForWidth());
        curr_loc_lbl->setSizePolicy(sizePolicy1);
        curr_loc_lbl->setMinimumSize(QSize(0, 15));
        curr_loc_lbl->setMaximumSize(QSize(16777215, 15));
        curr_loc_lbl->setFont(font8);
        curr_loc_lbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(curr_loc_lbl);


        verticalLayout_13->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        left_btn = new QPushButton(centralwidget);
        left_btn->setObjectName(QString::fromUtf8("left_btn"));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette16.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette16.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette16.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette16.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush);
        palette16.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette16.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette16.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette16.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette16.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette16.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette16.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette16.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette16.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette16.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette16.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette16.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette16.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        left_btn->setPalette(palette16);
        QFont font9;
        font9.setFamily(QString::fromUtf8("MS Serif"));
        font9.setPointSize(11);
        font9.setBold(true);
        font9.setWeight(75);
        left_btn->setFont(font9);

        verticalLayout_12->addWidget(left_btn);

        right_btn = new QPushButton(centralwidget);
        right_btn->setObjectName(QString::fromUtf8("right_btn"));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette17.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette17.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette17.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette17.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush);
        palette17.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette17.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette17.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette17.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette17.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette17.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette17.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette17.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette17.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette17.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette17.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette17.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette17.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        right_btn->setPalette(palette17);
        right_btn->setFont(font9);

        verticalLayout_12->addWidget(right_btn);


        horizontalLayout_14->addLayout(verticalLayout_12);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        up_btn = new QPushButton(centralwidget);
        up_btn->setObjectName(QString::fromUtf8("up_btn"));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette18.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette18.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette18.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette18.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush);
        palette18.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette18.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette18.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette18.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette18.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette18.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette18.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette18.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette18.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette18.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette18.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette18.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette18.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette18.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette18.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette18.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette18.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette18.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette18.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette18.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        up_btn->setPalette(palette18);
        up_btn->setFont(font1);

        verticalLayout_11->addWidget(up_btn);

        down_btn = new QPushButton(centralwidget);
        down_btn->setObjectName(QString::fromUtf8("down_btn"));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette19.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette19.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette19.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette19.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette19.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette19.setBrush(QPalette::Active, QPalette::Text, brush);
        palette19.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette19.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette19.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette19.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette19.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette19.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette19.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette19.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette19.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette19.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette19.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette19.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette19.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette19.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette19.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette19.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette19.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette19.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette19.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette19.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette19.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette19.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette19.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette19.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette19.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette19.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette19.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette19.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette19.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette19.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette19.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        down_btn->setPalette(palette19);
        down_btn->setFont(font1);

        verticalLayout_11->addWidget(down_btn);


        horizontalLayout_14->addLayout(verticalLayout_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        zoom_in_btn = new QPushButton(centralwidget);
        zoom_in_btn->setObjectName(QString::fromUtf8("zoom_in_btn"));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette20.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette20.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette20.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette20.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette20.setBrush(QPalette::Active, QPalette::Text, brush);
        palette20.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette20.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette20.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette20.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette20.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette20.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette20.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette20.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette20.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette20.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette20.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette20.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette20.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette20.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette20.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette20.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette20.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette20.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette20.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette20.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette20.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette20.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette20.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette20.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette20.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette20.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette20.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette20.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette20.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette20.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        zoom_in_btn->setPalette(palette20);
        zoom_in_btn->setFont(font9);

        verticalLayout_10->addWidget(zoom_in_btn);

        zoom_out_btn = new QPushButton(centralwidget);
        zoom_out_btn->setObjectName(QString::fromUtf8("zoom_out_btn"));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette21.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette21.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette21.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette21.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette21.setBrush(QPalette::Active, QPalette::Text, brush);
        palette21.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette21.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette21.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette21.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette21.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette21.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette21.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette21.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette21.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette21.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette21.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette21.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette21.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette21.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette21.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette21.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette21.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette21.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette21.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette21.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette21.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette21.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette21.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette21.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette21.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette21.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette21.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette21.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette21.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette21.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        zoom_out_btn->setPalette(palette21);
        zoom_out_btn->setFont(font9);

        verticalLayout_10->addWidget(zoom_out_btn);


        horizontalLayout_14->addLayout(verticalLayout_10);


        verticalLayout_13->addLayout(horizontalLayout_14);


        verticalLayout_15->addLayout(verticalLayout_13);


        horizontalLayout_11->addLayout(verticalLayout_15);

        horizontalLayout_11->setStretch(0, 50);
        horizontalLayout_11->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(x_box, y_box);
        QWidget::setTabOrder(y_box, z_box);

        retranslateUi(MainWindow);

        cams_list->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Lab 03", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        rotate_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        move_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        scale_btn->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261.", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\320\265\321\200\320\270\320\260\320\273", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\320\264\320\265\320\272\321\201 \320\277\321\200\320\265\320\273\320\276\320\274\320\273.", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\321\214\320\261\320\265\320\264\320\276", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\320\224\320\270\321\204\321\204. \321\206\320\262\320\265\321\202", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\265\320\272. \321\215\320\272\321\201\320\277\320\276\320\275\320\265\320\275\321\202", nullptr));
        stuuub->setText(QCoreApplication::translate("MainWindow", "STUB", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\241\320\262\320\265\321\202", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214", nullptr));
        add_light_btn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        load_light_btn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        stub->setText(QCoreApplication::translate("MainWindow", "STUB", nullptr));
        rm_light_btn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\321\213", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217", nullptr));
        curr_camera_lbl->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        add_camera_btn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        change_camera_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\272\320\273.", nullptr));
        rm_cam_btn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\320\270", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217", nullptr));
        curr_model_lbl->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        load_model_btn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        change_model_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\272\320\273.", nullptr));
        rm_mod_btn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        load_light_btn_3->setText(QCoreApplication::translate("MainWindow", "STUB", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        curr_loc_lbl->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        left_btn->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
        right_btn->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
        up_btn->setText(QCoreApplication::translate("MainWindow", "\342\254\206", nullptr));
        down_btn->setText(QCoreApplication::translate("MainWindow", "\342\254\207", nullptr));
        zoom_in_btn->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        zoom_out_btn->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGN_H
