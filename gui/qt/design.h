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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout_9;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *cam_move_left_btn;
    QPushButton *cam_turn_left_btn;
    QPushButton *cam_move_up_btn;
    QPushButton *cam_turn_up_btn;
    QPushButton *cam_zoom_in_btn;
    QLabel *label_4;
    QDoubleSpinBox *cam_x_box;
    QLabel *label_5;
    QDoubleSpinBox *cam_y_box;
    QLabel *label_6;
    QDoubleSpinBox *cam_z_box;
    QLabel *label_23;
    QSpinBox *cam_turn_box;
    QPushButton *cam_zoom_out_btn;
    QPushButton *cam_turn_down_btn;
    QPushButton *cam_move_down_btn;
    QPushButton *cam_turn_right_btn;
    QPushButton *cam_move_right_btn;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label;
    QDoubleSpinBox *x_box;
    QLabel *label_3;
    QDoubleSpinBox *y_box;
    QLabel *label_2;
    QDoubleSpinBox *z_box;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *scale_btn;
    QPushButton *rotate_btn;
    QPushButton *move_btn;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_25;
    QLabel *mod_curr_lbl;
    QListWidget *models_list;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *mod_load_btn;
    QPushButton *mod_rm_btn;
    QPushButton *mod_switch_btn;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_15;
    QDoubleSpinBox *color0_box;
    QDoubleSpinBox *color1_box;
    QDoubleSpinBox *color2_box;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QDoubleSpinBox *alb0_box;
    QDoubleSpinBox *alb1_box;
    QDoubleSpinBox *alb2_box;
    QDoubleSpinBox *alb3_box;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_16;
    QDoubleSpinBox *spec_exp_box;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_24;
    QDoubleSpinBox *ambient_box;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_11;
    QDoubleSpinBox *refr_idx_box;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *mat_apply_btn;
    QPushButton *mat_load_btn;
    QVBoxLayout *verticalLayout;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_20;
    QDoubleSpinBox *scene_ambient_box;
    QLabel *label_19;
    QSpinBox *rtree_h_box;
    QPushButton *rtree_h_apply_btn;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QDoubleSpinBox *light_x_box;
    QLabel *label_9;
    QDoubleSpinBox *light_y_box;
    QLabel *label_22;
    QDoubleSpinBox *light_z_box;
    QLabel *label_17;
    QDoubleSpinBox *light_intensity_box;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_27;
    QLabel *light_curr_lbl;
    QListWidget *lights_list;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *light_add_btn;
    QPushButton *light_load_btn;
    QPushButton *light_rm_btn;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *light_switch_btn;
    QPushButton *light_apply_btn;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_21;
    QSpinBox *cam_fov_box;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_29;
    QLabel *cam_curr_lbl;
    QListWidget *cams_list;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *cam_apply_btn;
    QPushButton *cam_add_btn;
    QPushButton *cam_rm_btn;
    QPushButton *cam_switch_btn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1650, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1650, 1000));
        MainWindow->setMaximumSize(QSize(1650, 1000));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(170, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(237, 237, 237, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(197, 197, 197, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(79, 79, 79, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(105, 105, 105, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        QBrush brush7(QColor(158, 158, 158, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush8(QColor(206, 206, 206, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush10(QColor(0, 0, 0, 128));
        brush10.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        MainWindow->setPalette(palette);
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setToolTipDuration(12);
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_18 = new QHBoxLayout(centralwidget);
        horizontalLayout_18->setSpacing(5);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 2, 2);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(9);
        graphicsView->setFont(font);
        graphicsView->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        verticalLayout_9->addWidget(graphicsView);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        cam_move_left_btn = new QPushButton(centralwidget);
        cam_move_left_btn->setObjectName(QString::fromUtf8("cam_move_left_btn"));
        cam_move_left_btn->setMinimumSize(QSize(75, 24));
        cam_move_left_btn->setMaximumSize(QSize(75, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStyleStrategy(QFont::PreferAntialias);
        cam_move_left_btn->setFont(font1);
        cam_move_left_btn->setCursor(QCursor(Qt::PointingHandCursor));
        cam_move_left_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_17->addWidget(cam_move_left_btn);

        cam_turn_left_btn = new QPushButton(centralwidget);
        cam_turn_left_btn->setObjectName(QString::fromUtf8("cam_turn_left_btn"));
        cam_turn_left_btn->setMinimumSize(QSize(75, 24));
        cam_turn_left_btn->setMaximumSize(QSize(75, 24));
        cam_turn_left_btn->setFont(font1);
        cam_turn_left_btn->setCursor(QCursor(Qt::PointingHandCursor));
        cam_turn_left_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_17->addWidget(cam_turn_left_btn);

        cam_move_up_btn = new QPushButton(centralwidget);
        cam_move_up_btn->setObjectName(QString::fromUtf8("cam_move_up_btn"));
        cam_move_up_btn->setMinimumSize(QSize(75, 24));
        cam_move_up_btn->setMaximumSize(QSize(75, 24));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        font2.setStyleStrategy(QFont::PreferAntialias);
        cam_move_up_btn->setFont(font2);
        cam_move_up_btn->setCursor(QCursor(Qt::PointingHandCursor));
        cam_move_up_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_17->addWidget(cam_move_up_btn);

        cam_turn_up_btn = new QPushButton(centralwidget);
        cam_turn_up_btn->setObjectName(QString::fromUtf8("cam_turn_up_btn"));
        cam_turn_up_btn->setMinimumSize(QSize(75, 24));
        cam_turn_up_btn->setMaximumSize(QSize(75, 24));
        cam_turn_up_btn->setFont(font2);
        cam_turn_up_btn->setCursor(QCursor(Qt::PointingHandCursor));
        cam_turn_up_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_17->addWidget(cam_turn_up_btn);

        cam_zoom_in_btn = new QPushButton(centralwidget);
        cam_zoom_in_btn->setObjectName(QString::fromUtf8("cam_zoom_in_btn"));
        cam_zoom_in_btn->setMinimumSize(QSize(75, 24));
        cam_zoom_in_btn->setMaximumSize(QSize(75, 24));
        cam_zoom_in_btn->setFont(font1);
        cam_zoom_in_btn->setCursor(QCursor(Qt::PointingHandCursor));
        cam_zoom_in_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_17->addWidget(cam_zoom_in_btn);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Lucida Console"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label_4->setFont(font3);
        label_4->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_4);

        cam_x_box = new QDoubleSpinBox(centralwidget);
        cam_x_box->setObjectName(QString::fromUtf8("cam_x_box"));
        cam_x_box->setMinimumSize(QSize(50, 25));
        cam_x_box->setMaximumSize(QSize(50, 25));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Cambria Math"));
        font4.setPointSize(10);
        cam_x_box->setFont(font4);
        cam_x_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        cam_x_box->setAlignment(Qt::AlignCenter);
        cam_x_box->setReadOnly(true);
        cam_x_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        cam_x_box->setMinimum(-10000000000000000.000000000000000);
        cam_x_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_17->addWidget(cam_x_box);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setFont(font3);
        label_5->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_5);

        cam_y_box = new QDoubleSpinBox(centralwidget);
        cam_y_box->setObjectName(QString::fromUtf8("cam_y_box"));
        cam_y_box->setMinimumSize(QSize(50, 25));
        cam_y_box->setMaximumSize(QSize(50, 25));
        cam_y_box->setFont(font4);
        cam_y_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        cam_y_box->setAlignment(Qt::AlignCenter);
        cam_y_box->setReadOnly(true);
        cam_y_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        cam_y_box->setMinimum(-10000000000000000.000000000000000);
        cam_y_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_17->addWidget(cam_y_box);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font3);
        label_6->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label_6);

        cam_z_box = new QDoubleSpinBox(centralwidget);
        cam_z_box->setObjectName(QString::fromUtf8("cam_z_box"));
        cam_z_box->setMinimumSize(QSize(50, 25));
        cam_z_box->setMaximumSize(QSize(50, 25));
        cam_z_box->setFont(font4);
        cam_z_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        cam_z_box->setAlignment(Qt::AlignCenter);
        cam_z_box->setReadOnly(true);
        cam_z_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        cam_z_box->setMinimum(-10000000000000000.000000000000000);
        cam_z_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_17->addWidget(cam_z_box);

        label_23 = new QLabel(centralwidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy2);
        label_23->setMinimumSize(QSize(0, 15));
        label_23->setMaximumSize(QSize(16777215, 15));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        label_23->setFont(font5);
        label_23->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_23->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_17->addWidget(label_23);

        cam_turn_box = new QSpinBox(centralwidget);
        cam_turn_box->setObjectName(QString::fromUtf8("cam_turn_box"));
        sizePolicy.setHeightForWidth(cam_turn_box->sizePolicy().hasHeightForWidth());
        cam_turn_box->setSizePolicy(sizePolicy);
        cam_turn_box->setMinimumSize(QSize(50, 25));
        cam_turn_box->setMaximumSize(QSize(50, 25));
        cam_turn_box->setFont(font4);
        cam_turn_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        cam_turn_box->setAlignment(Qt::AlignCenter);
        cam_turn_box->setReadOnly(true);
        cam_turn_box->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_17->addWidget(cam_turn_box);

        cam_zoom_out_btn = new QPushButton(centralwidget);
        cam_zoom_out_btn->setObjectName(QString::fromUtf8("cam_zoom_out_btn"));
        cam_zoom_out_btn->setMinimumSize(QSize(75, 24));
        cam_zoom_out_btn->setMaximumSize(QSize(75, 24));
        cam_zoom_out_btn->setFont(font1);
        cam_zoom_out_btn->setCursor(QCursor(Qt::PointingHandCursor));
        cam_zoom_out_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_17->addWidget(cam_zoom_out_btn);

        cam_turn_down_btn = new QPushButton(centralwidget);
        cam_turn_down_btn->setObjectName(QString::fromUtf8("cam_turn_down_btn"));
        cam_turn_down_btn->setMinimumSize(QSize(75, 24));
        cam_turn_down_btn->setMaximumSize(QSize(75, 24));
        cam_turn_down_btn->setFont(font2);
        cam_turn_down_btn->setCursor(QCursor(Qt::PointingHandCursor));
        cam_turn_down_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_17->addWidget(cam_turn_down_btn);

        cam_move_down_btn = new QPushButton(centralwidget);
        cam_move_down_btn->setObjectName(QString::fromUtf8("cam_move_down_btn"));
        cam_move_down_btn->setMinimumSize(QSize(75, 24));
        cam_move_down_btn->setMaximumSize(QSize(75, 24));
        cam_move_down_btn->setFont(font2);
        cam_move_down_btn->setCursor(QCursor(Qt::PointingHandCursor));
        cam_move_down_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_17->addWidget(cam_move_down_btn);

        cam_turn_right_btn = new QPushButton(centralwidget);
        cam_turn_right_btn->setObjectName(QString::fromUtf8("cam_turn_right_btn"));
        cam_turn_right_btn->setMinimumSize(QSize(75, 24));
        cam_turn_right_btn->setMaximumSize(QSize(75, 24));
        cam_turn_right_btn->setFont(font1);
        cam_turn_right_btn->setCursor(QCursor(Qt::PointingHandCursor));
        cam_turn_right_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_17->addWidget(cam_turn_right_btn);

        cam_move_right_btn = new QPushButton(centralwidget);
        cam_move_right_btn->setObjectName(QString::fromUtf8("cam_move_right_btn"));
        cam_move_right_btn->setMinimumSize(QSize(75, 24));
        cam_move_right_btn->setMaximumSize(QSize(75, 24));
        cam_move_right_btn->setFont(font1);
        cam_move_right_btn->setCursor(QCursor(Qt::PointingHandCursor));
        cam_move_right_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        cam_move_right_btn->setCheckable(false);
        cam_move_right_btn->setAutoDefault(false);
        cam_move_right_btn->setFlat(false);

        horizontalLayout_17->addWidget(cam_move_right_btn);


        verticalLayout_9->addLayout(horizontalLayout_17);


        horizontalLayout_18->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial Black"));
        font6.setPointSize(11);
        label_13->setFont(font6);
        label_13->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Lucida Console"));
        font7.setPointSize(10);
        font7.setBold(true);
        font7.setWeight(75);
        label->setFont(font7);
        label->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label);

        x_box = new QDoubleSpinBox(centralwidget);
        x_box->setObjectName(QString::fromUtf8("x_box"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(x_box->sizePolicy().hasHeightForWidth());
        x_box->setSizePolicy(sizePolicy3);
        x_box->setMinimumSize(QSize(48, 25));
        x_box->setMaximumSize(QSize(50, 25));
        x_box->setFont(font4);
        x_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        x_box->setWrapping(false);
        x_box->setAlignment(Qt::AlignCenter);
        x_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        x_box->setAccelerated(false);
        x_box->setMinimum(-10000000000000000.000000000000000);
        x_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_12->addWidget(x_box);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font7);
        label_3->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_3);

        y_box = new QDoubleSpinBox(centralwidget);
        y_box->setObjectName(QString::fromUtf8("y_box"));
        sizePolicy3.setHeightForWidth(y_box->sizePolicy().hasHeightForWidth());
        y_box->setSizePolicy(sizePolicy3);
        y_box->setMinimumSize(QSize(48, 25));
        y_box->setMaximumSize(QSize(50, 25));
        y_box->setFont(font4);
        y_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        y_box->setWrapping(false);
        y_box->setAlignment(Qt::AlignCenter);
        y_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        y_box->setAccelerated(false);
        y_box->setMinimum(-10000000000000000.000000000000000);
        y_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_12->addWidget(y_box);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font7);
        label_2->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_2);

        z_box = new QDoubleSpinBox(centralwidget);
        z_box->setObjectName(QString::fromUtf8("z_box"));
        sizePolicy3.setHeightForWidth(z_box->sizePolicy().hasHeightForWidth());
        z_box->setSizePolicy(sizePolicy3);
        z_box->setMinimumSize(QSize(48, 25));
        z_box->setMaximumSize(QSize(50, 25));
        z_box->setFont(font4);
        z_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        z_box->setWrapping(false);
        z_box->setAlignment(Qt::AlignCenter);
        z_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        z_box->setAccelerated(false);
        z_box->setMinimum(-10000000000000000.000000000000000);
        z_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_12->addWidget(z_box);


        verticalLayout_7->addLayout(horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        scale_btn = new QPushButton(centralwidget);
        scale_btn->setObjectName(QString::fromUtf8("scale_btn"));
        sizePolicy2.setHeightForWidth(scale_btn->sizePolicy().hasHeightForWidth());
        scale_btn->setSizePolicy(sizePolicy2);
        scale_btn->setMinimumSize(QSize(75, 30));
        scale_btn->setMaximumSize(QSize(75, 30));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        QBrush brush11(QColor(127, 127, 127, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush11);
        QBrush brush12(QColor(170, 170, 170, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        scale_btn->setPalette(palette1);
        QFont font8;
        font8.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font8.setPointSize(10);
        scale_btn->setFont(font8);
        scale_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_14->addWidget(scale_btn);

        rotate_btn = new QPushButton(centralwidget);
        rotate_btn->setObjectName(QString::fromUtf8("rotate_btn"));
        sizePolicy2.setHeightForWidth(rotate_btn->sizePolicy().hasHeightForWidth());
        rotate_btn->setSizePolicy(sizePolicy2);
        rotate_btn->setMinimumSize(QSize(75, 30));
        rotate_btn->setMaximumSize(QSize(75, 30));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        rotate_btn->setPalette(palette2);
        rotate_btn->setFont(font8);
        rotate_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_14->addWidget(rotate_btn);

        move_btn = new QPushButton(centralwidget);
        move_btn->setObjectName(QString::fromUtf8("move_btn"));
        sizePolicy2.setHeightForWidth(move_btn->sizePolicy().hasHeightForWidth());
        move_btn->setSizePolicy(sizePolicy2);
        move_btn->setMinimumSize(QSize(75, 30));
        move_btn->setMaximumSize(QSize(75, 30));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        move_btn->setPalette(palette3);
        move_btn->setFont(font8);
        move_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_14->addWidget(move_btn);


        verticalLayout_7->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_25 = new QLabel(centralwidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        sizePolicy.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy);
        label_25->setMinimumSize(QSize(0, 15));
        label_25->setMaximumSize(QSize(16777215, 15));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font9.setPointSize(12);
        font9.setBold(false);
        font9.setWeight(50);
        label_25->setFont(font9);
        label_25->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_25->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_16->addWidget(label_25);

        mod_curr_lbl = new QLabel(centralwidget);
        mod_curr_lbl->setObjectName(QString::fromUtf8("mod_curr_lbl"));
        sizePolicy.setHeightForWidth(mod_curr_lbl->sizePolicy().hasHeightForWidth());
        mod_curr_lbl->setSizePolicy(sizePolicy);
        mod_curr_lbl->setMinimumSize(QSize(0, 15));
        mod_curr_lbl->setMaximumSize(QSize(16777215, 15));
        mod_curr_lbl->setFont(font9);
        mod_curr_lbl->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        mod_curr_lbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_16->addWidget(mod_curr_lbl);


        verticalLayout_7->addLayout(horizontalLayout_16);

        models_list = new QListWidget(centralwidget);
        models_list->setObjectName(QString::fromUtf8("models_list"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(models_list->sizePolicy().hasHeightForWidth());
        models_list->setSizePolicy(sizePolicy4);
        models_list->setMinimumSize(QSize(316, 100));
        models_list->setMaximumSize(QSize(316, 100));
        QFont font10;
        font10.setPointSize(10);
        models_list->setFont(font10);
        models_list->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        verticalLayout_7->addWidget(models_list);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        mod_load_btn = new QPushButton(centralwidget);
        mod_load_btn->setObjectName(QString::fromUtf8("mod_load_btn"));
        sizePolicy2.setHeightForWidth(mod_load_btn->sizePolicy().hasHeightForWidth());
        mod_load_btn->setSizePolicy(sizePolicy2);
        mod_load_btn->setMinimumSize(QSize(75, 30));
        mod_load_btn->setMaximumSize(QSize(75, 30));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        mod_load_btn->setPalette(palette4);
        mod_load_btn->setFont(font8);
        mod_load_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_15->addWidget(mod_load_btn);

        mod_rm_btn = new QPushButton(centralwidget);
        mod_rm_btn->setObjectName(QString::fromUtf8("mod_rm_btn"));
        sizePolicy2.setHeightForWidth(mod_rm_btn->sizePolicy().hasHeightForWidth());
        mod_rm_btn->setSizePolicy(sizePolicy2);
        mod_rm_btn->setMinimumSize(QSize(75, 30));
        mod_rm_btn->setMaximumSize(QSize(75, 30));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        mod_rm_btn->setPalette(palette5);
        mod_rm_btn->setFont(font8);
        mod_rm_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_15->addWidget(mod_rm_btn);

        mod_switch_btn = new QPushButton(centralwidget);
        mod_switch_btn->setObjectName(QString::fromUtf8("mod_switch_btn"));
        sizePolicy2.setHeightForWidth(mod_switch_btn->sizePolicy().hasHeightForWidth());
        mod_switch_btn->setSizePolicy(sizePolicy2);
        mod_switch_btn->setMinimumSize(QSize(75, 30));
        mod_switch_btn->setMaximumSize(QSize(75, 30));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        mod_switch_btn->setPalette(palette6);
        mod_switch_btn->setFont(font8);
        mod_switch_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_15->addWidget(mod_switch_btn);


        verticalLayout_7->addLayout(horizontalLayout_15);


        verticalLayout_8->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy5);
        label_18->setMinimumSize(QSize(0, 15));
        label_18->setMaximumSize(QSize(16777215, 15));
        label_18->setFont(font6);
        label_18->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_18->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_18);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy2.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy2);
        label_15->setMinimumSize(QSize(0, 15));
        label_15->setMaximumSize(QSize(16777215, 15));
        QFont font11;
        font11.setFamily(QString::fromUtf8("Bahnschrift Condensed"));
        font11.setPointSize(10);
        font11.setBold(true);
        font11.setWeight(75);
        label_15->setFont(font11);
        label_15->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_15);

        color0_box = new QDoubleSpinBox(centralwidget);
        color0_box->setObjectName(QString::fromUtf8("color0_box"));
        sizePolicy.setHeightForWidth(color0_box->sizePolicy().hasHeightForWidth());
        color0_box->setSizePolicy(sizePolicy);
        color0_box->setMinimumSize(QSize(55, 25));
        color0_box->setMaximumSize(QSize(40, 25));
        color0_box->setFont(font4);
        color0_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        color0_box->setAlignment(Qt::AlignCenter);
        color0_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        color0_box->setMinimum(-10000000000000000.000000000000000);
        color0_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_11->addWidget(color0_box);

        color1_box = new QDoubleSpinBox(centralwidget);
        color1_box->setObjectName(QString::fromUtf8("color1_box"));
        sizePolicy.setHeightForWidth(color1_box->sizePolicy().hasHeightForWidth());
        color1_box->setSizePolicy(sizePolicy);
        color1_box->setMinimumSize(QSize(55, 25));
        color1_box->setMaximumSize(QSize(40, 25));
        color1_box->setFont(font4);
        color1_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        color1_box->setAlignment(Qt::AlignCenter);
        color1_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        color1_box->setMinimum(-10000000000000000.000000000000000);
        color1_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_11->addWidget(color1_box);

        color2_box = new QDoubleSpinBox(centralwidget);
        color2_box->setObjectName(QString::fromUtf8("color2_box"));
        sizePolicy.setHeightForWidth(color2_box->sizePolicy().hasHeightForWidth());
        color2_box->setSizePolicy(sizePolicy);
        color2_box->setMinimumSize(QSize(55, 25));
        color2_box->setMaximumSize(QSize(40, 25));
        color2_box->setFont(font4);
        color2_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        color2_box->setAlignment(Qt::AlignCenter);
        color2_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        color2_box->setMinimum(-10000000000000000.000000000000000);
        color2_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_11->addWidget(color2_box);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 1);
        horizontalLayout_11->setStretch(3, 1);

        verticalLayout_6->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);
        label_12->setMinimumSize(QSize(0, 15));
        label_12->setMaximumSize(QSize(16777215, 15));
        label_12->setFont(font11);
        label_12->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_12);

        alb0_box = new QDoubleSpinBox(centralwidget);
        alb0_box->setObjectName(QString::fromUtf8("alb0_box"));
        sizePolicy.setHeightForWidth(alb0_box->sizePolicy().hasHeightForWidth());
        alb0_box->setSizePolicy(sizePolicy);
        alb0_box->setMinimumSize(QSize(40, 25));
        alb0_box->setMaximumSize(QSize(40, 25));
        alb0_box->setFont(font4);
        alb0_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        alb0_box->setAlignment(Qt::AlignCenter);
        alb0_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alb0_box->setMinimum(-10000000000000000.000000000000000);
        alb0_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_10->addWidget(alb0_box);

        alb1_box = new QDoubleSpinBox(centralwidget);
        alb1_box->setObjectName(QString::fromUtf8("alb1_box"));
        sizePolicy.setHeightForWidth(alb1_box->sizePolicy().hasHeightForWidth());
        alb1_box->setSizePolicy(sizePolicy);
        alb1_box->setMinimumSize(QSize(40, 25));
        alb1_box->setMaximumSize(QSize(40, 25));
        alb1_box->setFont(font4);
        alb1_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        alb1_box->setAlignment(Qt::AlignCenter);
        alb1_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alb1_box->setMinimum(-10000000000000000.000000000000000);
        alb1_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_10->addWidget(alb1_box);

        alb2_box = new QDoubleSpinBox(centralwidget);
        alb2_box->setObjectName(QString::fromUtf8("alb2_box"));
        sizePolicy.setHeightForWidth(alb2_box->sizePolicy().hasHeightForWidth());
        alb2_box->setSizePolicy(sizePolicy);
        alb2_box->setMinimumSize(QSize(40, 25));
        alb2_box->setMaximumSize(QSize(40, 25));
        alb2_box->setFont(font4);
        alb2_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        alb2_box->setAlignment(Qt::AlignCenter);
        alb2_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alb2_box->setMinimum(-10000000000000000.000000000000000);
        alb2_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_10->addWidget(alb2_box);

        alb3_box = new QDoubleSpinBox(centralwidget);
        alb3_box->setObjectName(QString::fromUtf8("alb3_box"));
        sizePolicy.setHeightForWidth(alb3_box->sizePolicy().hasHeightForWidth());
        alb3_box->setSizePolicy(sizePolicy);
        alb3_box->setMinimumSize(QSize(40, 25));
        alb3_box->setMaximumSize(QSize(40, 25));
        alb3_box->setFont(font4);
        alb3_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        alb3_box->setAlignment(Qt::AlignCenter);
        alb3_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alb3_box->setMinimum(-10000000000000000.000000000000000);
        alb3_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout_10->addWidget(alb3_box);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 1);
        horizontalLayout_10->setStretch(2, 1);
        horizontalLayout_10->setStretch(3, 1);

        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy2.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy2);
        label_16->setMinimumSize(QSize(0, 15));
        label_16->setMaximumSize(QSize(16777215, 15));
        label_16->setFont(font11);
        label_16->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_16);

        spec_exp_box = new QDoubleSpinBox(centralwidget);
        spec_exp_box->setObjectName(QString::fromUtf8("spec_exp_box"));
        sizePolicy2.setHeightForWidth(spec_exp_box->sizePolicy().hasHeightForWidth());
        spec_exp_box->setSizePolicy(sizePolicy2);
        spec_exp_box->setMinimumSize(QSize(0, 25));
        spec_exp_box->setMaximumSize(QSize(67, 25));
        spec_exp_box->setFont(font4);
        spec_exp_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        spec_exp_box->setAlignment(Qt::AlignCenter);
        spec_exp_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spec_exp_box->setMinimum(-10000000000000000.000000000000000);
        spec_exp_box->setMaximum(10000000000000000.000000000000000);

        verticalLayout_3->addWidget(spec_exp_box);


        horizontalLayout_9->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        sizePolicy2.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy2);
        label_24->setMinimumSize(QSize(0, 15));
        label_24->setMaximumSize(QSize(16777215, 15));
        label_24->setFont(font11);
        label_24->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_24->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_24);

        ambient_box = new QDoubleSpinBox(centralwidget);
        ambient_box->setObjectName(QString::fromUtf8("ambient_box"));
        sizePolicy2.setHeightForWidth(ambient_box->sizePolicy().hasHeightForWidth());
        ambient_box->setSizePolicy(sizePolicy2);
        ambient_box->setMinimumSize(QSize(0, 25));
        ambient_box->setMaximumSize(QSize(67, 25));
        ambient_box->setFont(font4);
        ambient_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        ambient_box->setAlignment(Qt::AlignCenter);
        ambient_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ambient_box->setMinimum(-10000000000000000.000000000000000);
        ambient_box->setMaximum(10000000000000000.000000000000000);

        verticalLayout_4->addWidget(ambient_box);


        horizontalLayout_9->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);
        label_11->setMinimumSize(QSize(0, 15));
        label_11->setMaximumSize(QSize(16777215, 15));
        label_11->setFont(font11);
        label_11->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_11);

        refr_idx_box = new QDoubleSpinBox(centralwidget);
        refr_idx_box->setObjectName(QString::fromUtf8("refr_idx_box"));
        sizePolicy2.setHeightForWidth(refr_idx_box->sizePolicy().hasHeightForWidth());
        refr_idx_box->setSizePolicy(sizePolicy2);
        refr_idx_box->setMinimumSize(QSize(0, 25));
        refr_idx_box->setMaximumSize(QSize(67, 25));
        refr_idx_box->setFont(font4);
        refr_idx_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        refr_idx_box->setAlignment(Qt::AlignCenter);
        refr_idx_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        refr_idx_box->setMinimum(-10000000000000000.000000000000000);
        refr_idx_box->setMaximum(10000000000000000.000000000000000);

        verticalLayout_5->addWidget(refr_idx_box);


        horizontalLayout_9->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        mat_apply_btn = new QPushButton(centralwidget);
        mat_apply_btn->setObjectName(QString::fromUtf8("mat_apply_btn"));
        sizePolicy2.setHeightForWidth(mat_apply_btn->sizePolicy().hasHeightForWidth());
        mat_apply_btn->setSizePolicy(sizePolicy2);
        mat_apply_btn->setMinimumSize(QSize(75, 30));
        mat_apply_btn->setMaximumSize(QSize(75, 30));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        mat_apply_btn->setPalette(palette7);
        mat_apply_btn->setFont(font8);
        mat_apply_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_13->addWidget(mat_apply_btn);

        mat_load_btn = new QPushButton(centralwidget);
        mat_load_btn->setObjectName(QString::fromUtf8("mat_load_btn"));
        sizePolicy2.setHeightForWidth(mat_load_btn->sizePolicy().hasHeightForWidth());
        mat_load_btn->setSizePolicy(sizePolicy2);
        mat_load_btn->setMinimumSize(QSize(75, 30));
        mat_load_btn->setMaximumSize(QSize(75, 30));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        mat_load_btn->setPalette(palette8);
        mat_load_btn->setFont(font8);
        mat_load_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_13->addWidget(mat_load_btn);


        verticalLayout_6->addLayout(horizontalLayout_13);


        verticalLayout_8->addLayout(verticalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy5.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy5);
        label_14->setMinimumSize(QSize(0, 15));
        label_14->setMaximumSize(QSize(16777215, 15));
        label_14->setFont(font6);
        label_14->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_14);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(0, 15));
        label_20->setMaximumSize(QSize(16777215, 15));
        label_20->setFont(font11);
        label_20->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_20);

        scene_ambient_box = new QDoubleSpinBox(centralwidget);
        scene_ambient_box->setObjectName(QString::fromUtf8("scene_ambient_box"));
        sizePolicy.setHeightForWidth(scene_ambient_box->sizePolicy().hasHeightForWidth());
        scene_ambient_box->setSizePolicy(sizePolicy);
        scene_ambient_box->setMinimumSize(QSize(40, 25));
        scene_ambient_box->setMaximumSize(QSize(40, 25));
        scene_ambient_box->setFont(font4);
        scene_ambient_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        scene_ambient_box->setAlignment(Qt::AlignCenter);
        scene_ambient_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        scene_ambient_box->setMinimum(0.000000000000000);
        scene_ambient_box->setMaximum(1.000000000000000);
        scene_ambient_box->setSingleStep(0.010000000000000);
        scene_ambient_box->setValue(1.000000000000000);

        horizontalLayout_2->addWidget(scene_ambient_box);

        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(0, 15));
        label_19->setMaximumSize(QSize(16777215, 15));
        label_19->setFont(font11);
        label_19->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_19);

        rtree_h_box = new QSpinBox(centralwidget);
        rtree_h_box->setObjectName(QString::fromUtf8("rtree_h_box"));
        sizePolicy.setHeightForWidth(rtree_h_box->sizePolicy().hasHeightForWidth());
        rtree_h_box->setSizePolicy(sizePolicy);
        rtree_h_box->setMinimumSize(QSize(40, 25));
        rtree_h_box->setMaximumSize(QSize(40, 25));
        rtree_h_box->setFont(font4);
        rtree_h_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        rtree_h_box->setAlignment(Qt::AlignCenter);
        rtree_h_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        rtree_h_box->setMinimum(1);
        rtree_h_box->setMaximum(5);

        horizontalLayout_2->addWidget(rtree_h_box);

        rtree_h_apply_btn = new QPushButton(centralwidget);
        rtree_h_apply_btn->setObjectName(QString::fromUtf8("rtree_h_apply_btn"));
        sizePolicy2.setHeightForWidth(rtree_h_apply_btn->sizePolicy().hasHeightForWidth());
        rtree_h_apply_btn->setSizePolicy(sizePolicy2);
        rtree_h_apply_btn->setMinimumSize(QSize(75, 30));
        rtree_h_apply_btn->setMaximumSize(QSize(75, 30));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        rtree_h_apply_btn->setPalette(palette9);
        rtree_h_apply_btn->setFont(font8);
        rtree_h_apply_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_2->addWidget(rtree_h_apply_btn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setFont(font7);
        label_8->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_8);

        light_x_box = new QDoubleSpinBox(centralwidget);
        light_x_box->setObjectName(QString::fromUtf8("light_x_box"));
        sizePolicy.setHeightForWidth(light_x_box->sizePolicy().hasHeightForWidth());
        light_x_box->setSizePolicy(sizePolicy);
        light_x_box->setMinimumSize(QSize(40, 25));
        light_x_box->setMaximumSize(QSize(40, 25));
        light_x_box->setFont(font4);
        light_x_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        light_x_box->setAlignment(Qt::AlignCenter);
        light_x_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        light_x_box->setMinimum(-10000000000000000.000000000000000);
        light_x_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout->addWidget(light_x_box);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);
        label_9->setFont(font7);
        label_9->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_9);

        light_y_box = new QDoubleSpinBox(centralwidget);
        light_y_box->setObjectName(QString::fromUtf8("light_y_box"));
        sizePolicy.setHeightForWidth(light_y_box->sizePolicy().hasHeightForWidth());
        light_y_box->setSizePolicy(sizePolicy);
        light_y_box->setMinimumSize(QSize(40, 25));
        light_y_box->setMaximumSize(QSize(40, 25));
        light_y_box->setFont(font4);
        light_y_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        light_y_box->setAlignment(Qt::AlignCenter);
        light_y_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        light_y_box->setMinimum(-10000000000000000.000000000000000);
        light_y_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout->addWidget(light_y_box);

        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        sizePolicy2.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy2);
        label_22->setFont(font7);
        label_22->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_22);

        light_z_box = new QDoubleSpinBox(centralwidget);
        light_z_box->setObjectName(QString::fromUtf8("light_z_box"));
        sizePolicy.setHeightForWidth(light_z_box->sizePolicy().hasHeightForWidth());
        light_z_box->setSizePolicy(sizePolicy);
        light_z_box->setMinimumSize(QSize(40, 25));
        light_z_box->setMaximumSize(QSize(40, 25));
        light_z_box->setFont(font4);
        light_z_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        light_z_box->setAlignment(Qt::AlignCenter);
        light_z_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        light_z_box->setMinimum(-10000000000000000.000000000000000);
        light_z_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout->addWidget(light_z_box);

        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy2.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy2);
        label_17->setMinimumSize(QSize(0, 15));
        label_17->setMaximumSize(QSize(16777215, 15));
        label_17->setFont(font11);
        label_17->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_17);

        light_intensity_box = new QDoubleSpinBox(centralwidget);
        light_intensity_box->setObjectName(QString::fromUtf8("light_intensity_box"));
        sizePolicy.setHeightForWidth(light_intensity_box->sizePolicy().hasHeightForWidth());
        light_intensity_box->setSizePolicy(sizePolicy);
        light_intensity_box->setMinimumSize(QSize(40, 25));
        light_intensity_box->setMaximumSize(QSize(40, 25));
        light_intensity_box->setFont(font4);
        light_intensity_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        light_intensity_box->setAlignment(Qt::AlignCenter);
        light_intensity_box->setButtonSymbols(QAbstractSpinBox::NoButtons);
        light_intensity_box->setMinimum(0.010000000000000);
        light_intensity_box->setMaximum(10000000000000000.000000000000000);

        horizontalLayout->addWidget(light_intensity_box);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        sizePolicy.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy);
        label_27->setMinimumSize(QSize(0, 15));
        label_27->setMaximumSize(QSize(16777215, 15));
        label_27->setFont(font9);
        label_27->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_27->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_27);

        light_curr_lbl = new QLabel(centralwidget);
        light_curr_lbl->setObjectName(QString::fromUtf8("light_curr_lbl"));
        sizePolicy.setHeightForWidth(light_curr_lbl->sizePolicy().hasHeightForWidth());
        light_curr_lbl->setSizePolicy(sizePolicy);
        light_curr_lbl->setMinimumSize(QSize(0, 15));
        light_curr_lbl->setMaximumSize(QSize(16777215, 15));
        light_curr_lbl->setFont(font9);
        light_curr_lbl->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        light_curr_lbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(light_curr_lbl);


        verticalLayout->addLayout(horizontalLayout_3);

        lights_list = new QListWidget(centralwidget);
        lights_list->setObjectName(QString::fromUtf8("lights_list"));
        sizePolicy4.setHeightForWidth(lights_list->sizePolicy().hasHeightForWidth());
        lights_list->setSizePolicy(sizePolicy4);
        lights_list->setMinimumSize(QSize(316, 80));
        lights_list->setMaximumSize(QSize(316, 80));
        lights_list->setFont(font10);
        lights_list->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        verticalLayout->addWidget(lights_list);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        light_add_btn = new QPushButton(centralwidget);
        light_add_btn->setObjectName(QString::fromUtf8("light_add_btn"));
        sizePolicy2.setHeightForWidth(light_add_btn->sizePolicy().hasHeightForWidth());
        light_add_btn->setSizePolicy(sizePolicy2);
        light_add_btn->setMinimumSize(QSize(75, 30));
        light_add_btn->setMaximumSize(QSize(75, 30));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette10.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        light_add_btn->setPalette(palette10);
        light_add_btn->setFont(font8);
        light_add_btn->setAutoFillBackground(false);
        light_add_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_4->addWidget(light_add_btn);

        light_load_btn = new QPushButton(centralwidget);
        light_load_btn->setObjectName(QString::fromUtf8("light_load_btn"));
        sizePolicy2.setHeightForWidth(light_load_btn->sizePolicy().hasHeightForWidth());
        light_load_btn->setSizePolicy(sizePolicy2);
        light_load_btn->setMinimumSize(QSize(75, 30));
        light_load_btn->setMaximumSize(QSize(75, 30));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette11.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette11.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette11.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette11.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush);
        palette11.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette11.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette11.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        light_load_btn->setPalette(palette11);
        light_load_btn->setFont(font8);
        light_load_btn->setAutoFillBackground(false);
        light_load_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_4->addWidget(light_load_btn);

        light_rm_btn = new QPushButton(centralwidget);
        light_rm_btn->setObjectName(QString::fromUtf8("light_rm_btn"));
        sizePolicy2.setHeightForWidth(light_rm_btn->sizePolicy().hasHeightForWidth());
        light_rm_btn->setSizePolicy(sizePolicy2);
        light_rm_btn->setMinimumSize(QSize(75, 30));
        light_rm_btn->setMaximumSize(QSize(75, 30));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette12.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette12.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette12.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette12.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette12.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette12.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        light_rm_btn->setPalette(palette12);
        light_rm_btn->setFont(font8);
        light_rm_btn->setAutoFillBackground(false);
        light_rm_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_4->addWidget(light_rm_btn);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        light_switch_btn = new QPushButton(centralwidget);
        light_switch_btn->setObjectName(QString::fromUtf8("light_switch_btn"));
        sizePolicy2.setHeightForWidth(light_switch_btn->sizePolicy().hasHeightForWidth());
        light_switch_btn->setSizePolicy(sizePolicy2);
        light_switch_btn->setMinimumSize(QSize(75, 30));
        light_switch_btn->setMaximumSize(QSize(75, 30));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette13.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette13.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        light_switch_btn->setPalette(palette13);
        light_switch_btn->setFont(font8);
        light_switch_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_5->addWidget(light_switch_btn);

        light_apply_btn = new QPushButton(centralwidget);
        light_apply_btn->setObjectName(QString::fromUtf8("light_apply_btn"));
        sizePolicy2.setHeightForWidth(light_apply_btn->sizePolicy().hasHeightForWidth());
        light_apply_btn->setSizePolicy(sizePolicy2);
        light_apply_btn->setMinimumSize(QSize(75, 30));
        light_apply_btn->setMaximumSize(QSize(75, 30));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette14.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette14.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette14.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette14.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush);
        palette14.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette14.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette14.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette14.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette14.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        light_apply_btn->setPalette(palette14);
        light_apply_btn->setFont(font8);
        light_apply_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_5->addWidget(light_apply_btn);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy5.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy5);
        label_7->setMinimumSize(QSize(0, 15));
        label_7->setMaximumSize(QSize(16777215, 15));
        label_7->setFont(font6);
        label_7->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(234, 0));
        label_21->setMaximumSize(QSize(16777215, 15));
        label_21->setFont(font9);
        label_21->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_21);

        cam_fov_box = new QSpinBox(centralwidget);
        cam_fov_box->setObjectName(QString::fromUtf8("cam_fov_box"));
        sizePolicy.setHeightForWidth(cam_fov_box->sizePolicy().hasHeightForWidth());
        cam_fov_box->setSizePolicy(sizePolicy);
        cam_fov_box->setMinimumSize(QSize(40, 27));
        cam_fov_box->setMaximumSize(QSize(40, 25));
        cam_fov_box->setFont(font4);
        cam_fov_box->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        cam_fov_box->setAlignment(Qt::AlignCenter);
        cam_fov_box->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_6->addWidget(cam_fov_box);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_29 = new QLabel(centralwidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy6);
        label_29->setMaximumSize(QSize(16777215, 15));
        label_29->setFont(font9);
        label_29->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        label_29->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_29);

        cam_curr_lbl = new QLabel(centralwidget);
        cam_curr_lbl->setObjectName(QString::fromUtf8("cam_curr_lbl"));
        sizePolicy6.setHeightForWidth(cam_curr_lbl->sizePolicy().hasHeightForWidth());
        cam_curr_lbl->setSizePolicy(sizePolicy6);
        cam_curr_lbl->setMaximumSize(QSize(16777215, 15));
        cam_curr_lbl->setFont(font9);
        cam_curr_lbl->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        cam_curr_lbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(cam_curr_lbl);


        verticalLayout_2->addLayout(horizontalLayout_7);

        cams_list = new QListWidget(centralwidget);
        cams_list->setObjectName(QString::fromUtf8("cams_list"));
        sizePolicy4.setHeightForWidth(cams_list->sizePolicy().hasHeightForWidth());
        cams_list->setSizePolicy(sizePolicy4);
        cams_list->setMinimumSize(QSize(316, 80));
        cams_list->setMaximumSize(QSize(316, 80));
        cams_list->setFont(font10);
        cams_list->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        cams_list->setGridSize(QSize(1, 0));
        cams_list->setViewMode(QListView::ListMode);
        cams_list->setWordWrap(false);
        cams_list->setSelectionRectVisible(false);

        verticalLayout_2->addWidget(cams_list);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        cam_apply_btn = new QPushButton(centralwidget);
        cam_apply_btn->setObjectName(QString::fromUtf8("cam_apply_btn"));
        sizePolicy2.setHeightForWidth(cam_apply_btn->sizePolicy().hasHeightForWidth());
        cam_apply_btn->setSizePolicy(sizePolicy2);
        cam_apply_btn->setMinimumSize(QSize(75, 30));
        cam_apply_btn->setMaximumSize(QSize(75, 30));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette15.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush);
        palette15.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette15.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette15.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette15.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette15.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette15.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette15.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette15.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette15.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        cam_apply_btn->setPalette(palette15);
        cam_apply_btn->setFont(font8);
        cam_apply_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_8->addWidget(cam_apply_btn);

        cam_add_btn = new QPushButton(centralwidget);
        cam_add_btn->setObjectName(QString::fromUtf8("cam_add_btn"));
        sizePolicy2.setHeightForWidth(cam_add_btn->sizePolicy().hasHeightForWidth());
        cam_add_btn->setSizePolicy(sizePolicy2);
        cam_add_btn->setMinimumSize(QSize(75, 30));
        cam_add_btn->setMaximumSize(QSize(75, 30));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette16.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette16.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette16.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette16.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush);
        palette16.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette16.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette16.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette16.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette16.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        cam_add_btn->setPalette(palette16);
        cam_add_btn->setFont(font8);
        cam_add_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_8->addWidget(cam_add_btn);

        cam_rm_btn = new QPushButton(centralwidget);
        cam_rm_btn->setObjectName(QString::fromUtf8("cam_rm_btn"));
        sizePolicy2.setHeightForWidth(cam_rm_btn->sizePolicy().hasHeightForWidth());
        cam_rm_btn->setSizePolicy(sizePolicy2);
        cam_rm_btn->setMinimumSize(QSize(75, 30));
        cam_rm_btn->setMaximumSize(QSize(75, 30));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette17.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette17.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette17.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette17.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush);
        palette17.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette17.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette17.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette17.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette17.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        cam_rm_btn->setPalette(palette17);
        cam_rm_btn->setFont(font8);
        cam_rm_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_8->addWidget(cam_rm_btn);

        cam_switch_btn = new QPushButton(centralwidget);
        cam_switch_btn->setObjectName(QString::fromUtf8("cam_switch_btn"));
        sizePolicy2.setHeightForWidth(cam_switch_btn->sizePolicy().hasHeightForWidth());
        cam_switch_btn->setSizePolicy(sizePolicy2);
        cam_switch_btn->setMinimumSize(QSize(75, 30));
        cam_switch_btn->setMaximumSize(QSize(75, 30));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette18.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette18.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette18.setBrush(QPalette::Active, QPalette::Dark, brush11);
        palette18.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush);
        palette18.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette18.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette18.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette18.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette18.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette18.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette18.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette18.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette18.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette18.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        cam_switch_btn->setPalette(palette18);
        cam_switch_btn->setFont(font8);
        cam_switch_btn->setLocale(QLocale(QLocale::Russian, QLocale::Russia));

        horizontalLayout_8->addWidget(cam_switch_btn);


        verticalLayout_2->addLayout(horizontalLayout_8);


        verticalLayout_8->addLayout(verticalLayout_2);


        horizontalLayout_18->addLayout(verticalLayout_8);

        horizontalLayout_18->setStretch(0, 50);
        horizontalLayout_18->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(mod_load_btn, alb1_box);
        QWidget::setTabOrder(alb1_box, alb0_box);
        QWidget::setTabOrder(alb0_box, rotate_btn);
        QWidget::setTabOrder(rotate_btn, scale_btn);
        QWidget::setTabOrder(scale_btn, move_btn);
        QWidget::setTabOrder(move_btn, mod_switch_btn);
        QWidget::setTabOrder(mod_switch_btn, mod_rm_btn);
        QWidget::setTabOrder(mod_rm_btn, models_list);
        QWidget::setTabOrder(models_list, color0_box);
        QWidget::setTabOrder(color0_box, color2_box);
        QWidget::setTabOrder(color2_box, lights_list);
        QWidget::setTabOrder(lights_list, light_z_box);
        QWidget::setTabOrder(light_z_box, light_y_box);
        QWidget::setTabOrder(light_y_box, light_x_box);
        QWidget::setTabOrder(light_x_box, light_apply_btn);
        QWidget::setTabOrder(light_apply_btn, mat_apply_btn);
        QWidget::setTabOrder(mat_apply_btn, alb3_box);
        QWidget::setTabOrder(alb3_box, spec_exp_box);
        QWidget::setTabOrder(spec_exp_box, cam_move_right_btn);
        QWidget::setTabOrder(cam_move_right_btn, cam_move_up_btn);
        QWidget::setTabOrder(cam_move_up_btn, cam_move_down_btn);
        QWidget::setTabOrder(cam_move_down_btn, rtree_h_box);
        QWidget::setTabOrder(rtree_h_box, scene_ambient_box);
        QWidget::setTabOrder(scene_ambient_box, mat_load_btn);
        QWidget::setTabOrder(mat_load_btn, cam_turn_right_btn);
        QWidget::setTabOrder(cam_turn_right_btn, cam_x_box);
        QWidget::setTabOrder(cam_x_box, cam_y_box);
        QWidget::setTabOrder(cam_y_box, cam_z_box);
        QWidget::setTabOrder(cam_z_box, light_intensity_box);
        QWidget::setTabOrder(light_intensity_box, light_load_btn);
        QWidget::setTabOrder(light_load_btn, light_add_btn);
        QWidget::setTabOrder(light_add_btn, ambient_box);
        QWidget::setTabOrder(ambient_box, cam_add_btn);
        QWidget::setTabOrder(cam_add_btn, light_rm_btn);
        QWidget::setTabOrder(light_rm_btn, cam_turn_up_btn);
        QWidget::setTabOrder(cam_turn_up_btn, cam_turn_down_btn);
        QWidget::setTabOrder(cam_turn_down_btn, alb2_box);
        QWidget::setTabOrder(alb2_box, light_switch_btn);

        retranslateUi(MainWindow);

        cam_move_right_btn->setDefault(false);
        cams_list->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\321\203\321\200\321\201\320\276\320\262\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260", nullptr));
        cam_move_left_btn->setText(QCoreApplication::translate("MainWindow", "\342\227\200", nullptr));
        cam_turn_left_btn->setText(QCoreApplication::translate("MainWindow", "\342\206\266 ", nullptr));
        cam_move_up_btn->setText(QCoreApplication::translate("MainWindow", "\342\226\262", nullptr));
        cam_turn_up_btn->setText(QCoreApplication::translate("MainWindow", "\342\244\264", nullptr));
        cam_zoom_in_btn->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Turn \302\260", nullptr));
        cam_zoom_out_btn->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        cam_turn_down_btn->setText(QCoreApplication::translate("MainWindow", "\342\244\265", nullptr));
        cam_move_down_btn->setText(QCoreApplication::translate("MainWindow", "\342\226\274", nullptr));
        cam_turn_right_btn->setText(QCoreApplication::translate("MainWindow", "\342\206\267", nullptr));
        cam_move_right_btn->setText(QCoreApplication::translate("MainWindow", "\342\226\266", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        scale_btn->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261.", nullptr));
        rotate_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        move_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211:", nullptr));
        mod_curr_lbl->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        mod_load_btn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        mod_rm_btn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        mod_switch_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\272\320\273.", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\320\265\321\200\320\270\320\260\320\273", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\321\214\320\261\320\265\320\264\320\276", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Kexp", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Ka", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "RefrIdx", nullptr));
        mat_apply_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        mat_load_btn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\241\320\262\320\265\321\202", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\320\265\321\217\320\275\320\275\321\213\320\271", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\276\321\202\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
        rtree_h_apply_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211:", nullptr));
        light_curr_lbl->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        light_add_btn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        light_load_btn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        light_rm_btn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        light_switch_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\272\320\273.", nullptr));
        light_apply_btn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\321\213", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\273\320\260\321\201\321\202\321\214 \320\275\320\260\320\261\320\273\321\216\320\264\320\265\320\275\320\270\321\217\302\260", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211:", nullptr));
        cam_curr_lbl->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        cam_apply_btn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214", nullptr));
        cam_add_btn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        cam_rm_btn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        cam_switch_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\272\320\273.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGN_H
