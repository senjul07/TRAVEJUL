//compile: gcc `pkg-config --cflags gtk+-3.0` "main.c" -o "main" `pkg-config --libs gtk+-3.0`
//execute: ./main

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>


const int screenWidth = 1366, screenHight = 768;
int boxU_space, nboxU_space, boxU_side_margin, boxU_main_width;
int logo_width, logo_hight;
int imBack_width, imBack_hight;
int boxU_label_margin;
char *num1 = "0";
char *num2 = "0";
char *num3 = "0";
int pay = 0;
int sugar = 0;
int nummenu = 0;
int pilihmenu = 0;
int pilihharga1 = 0;
char format[200];
char markup_text[200];
char tmp1[128];
char tmp2[128];
char tmp3[128];

int data1 = 0;
int data2 = 0;
int data3 = 0;
int data4 = 0;
int data5 = 0;
int data6 = 0;
int data7 = 0;
int data8 = 0;
int data9 = 0;

int total = 0;

char pilihan[9][50] = {
	"Tiket Pesawat",
	"Hotel",
	"Cuaca",
	"Tiket Kereta",
	"Jadwal",
	"Tukar Uang",
	"Tiket Kapal Laut",
	"Telepon",
	"Pengaturan"
};

char imgpilihan[9][50] = {
	"img/logo_bt1.png",
	"img/logo_bt2.png",
	"img/logo_bt3.png",
	"img/logo_bt4.png",
	"img/logo_bt5.png",
	"img/logo_bt6.png",
	"img/logo_bt7.png",
	"img/logo_bt8.png",
	"img/logo_bt9.png"
};
	

char harga1[27][50] = {
	"Rp3.500.000",
	"Rp3.250.000",
	"Rp3.000.000",
	"Rp2.500.000",
	"Rp2.250.000",
	"Rp2.000.000",
	"Rp1.500.000",
	"Rp1.250.000",
	"Rp1.000.000",
	"Rp975.000",
	"Rp875.000",
	"Rp700.000",
	"Rp675.000",
	"Rp575.000",
	"Rp400.000",
	"Rp375.000",
	"Rp275.000",
	"Rp100.000",
	"Rp9.500.000",
	"Rp9.250.000",
	"Rp9.000.000",
	"Rp8.500.000",
	"Rp8.250.000",
	"Rp8.000.000",
	"Rp7.500.000",
	"Rp7.250.000",
	"Rp7.000.000",
};


char imgpay[5][50] = {
	"img/gopay.png",
	"img/dana.png",
	"img/ovo.png",
	"img/linkaja.png",
	"img/shopeepay.png"
};

GtkCssProvider *cssProvider;
GtkBuilder *builder;

//====================================================================//

//mainWindow
GtkWidget *windowMain;
GtkWidget *boxW; 
GtkWidget *boxW_grid, *hello_box;
GtkWidget *hello_logo;
GtkWidget *btn_hel;
GtkWidget *btn_lb_hel;

//window menu
GtkWidget *windowMenu;
GtkWidget *boxU, *boxU1, *menuC1;
GtkWidget *boxU1_grid1, *boxU1_H1, *boxU1_H2;
GtkWidget *btn1_U1, *btn2_U1, *btn3_U1, *btn4_U1, *btn5_U1, *btn6_U1, *btn7_U1, *btn8_U1, *btn9_U1;
GtkWidget *btn1_U1_U1, *btn2_U1_U2,  *btn3_U1_U3, *btn4_U1_U4, *btn5_U1_U5, *btn6_U1_U6, *btn7_U1_U7, *btn8_U1_U8, *btn9_U1_U9, *btnU1_cancel;
GtkWidget *btn1_U1_logo, *btn2_U1_logo, *btn3_U1_logo, *btn4_U1_logo, *btn5_U1_logo, *btn6_U1_logo, *btn7_U1_logo, *btn8_U1_logo, *btn9_U1_logo, *boxU1_logo;
GtkWidget *btn1_U1_lbl, *btn2_U1_lbl, *btn3_U1_lbl, *btn4_U1_lbl, *btn5_U1_lbl, *btn6_U1_lbl, *btn7_U1_lbl, *btn8_U1_lbl, *btn9_U1_lbl, *btnU1_cancel_lbl, *copywU1_lbl;

//window Temp1
GtkWidget *windowTemp1;
GtkWidget *boxT1, *MenuT1;
GtkWidget *boxT1_H1, *boxT1_H2, *boxT1_H1_H1, *boxT1_1, *boxT1_2;
GtkWidget *boxT1_logo;
GtkWidget *btnbox1_temp1, *btnbox2_temp1, *btnbox3_temp1, *btn_ok_T1, *btn_exit_T1;
GtkWidget *tujuan_entry1, *maskapai_entry1, *jam_entry1;
GtkWidget *btn_ok_T1_lbl, *btn_exit_T1_lbl, *jamT1_lbl, *tujuanT1_lbl, *maskapaiT1_lbl, *waktuT1_lbl, *box_T1_lbl;

//window Temp2
GtkWidget *windowTemp2;
GtkWidget *boxT2, *MenuT2;
GtkWidget *boxT2_H1, *boxT2_H2, *boxT2_H1_H1, *boxT2_1, *boxT2_2;
GtkWidget *boxT2_logo;
GtkWidget *btnbox1_temp2, *btnbox2_temp2, *btnbox3_temp2, *btn_ok_T2, *btn_exit_T2;
GtkWidget *tujuan_entry2, *kereta_entry2, *jam_entry2;
GtkWidget *btn_ok_T2_lbl, *btn_exit_T2_lbl, *jamT2_lbl, *tujuanT2_lbl, *keretaT2_lbl, *waktuT2_lbl, *box_T2_lbl;

//window Temp3
GtkWidget *windowTemp3;
GtkWidget *boxT3, *MenuT3;
GtkWidget *boxT3_H1, *boxT3_H2, *boxT3_H1_H1, *boxT3_1, *boxT3_2;
GtkWidget *boxT3_logo;
GtkWidget *btnbox1_temp3, *btnbox2_temp3, *btnbox3_temp3, *btn_ok_T3, *btn_exit_T3;
GtkWidget *tujuan_entry3, *kapal_entry3, *jam_entry3;
GtkWidget *btn_ok_T3_lbl, *btn_exit_T3_lbl, *jamT3_lbl, *tujuanT3_lbl, *kapalT3_lbl, *waktuT3_lbl, *box_T3_lbl;

//window payment
GtkWidget *windowPay;
GtkWidget *boxP, *menuP1;
GtkWidget *boxP1_grid1, *boxP1_H1, *boxP1_H2, *boxP1_H3, *boxP1_H4;
GtkWidget *btn1_P1, *btn2_P1, *btn3_P1, *btn4_P1, *btn5_P1, *btn6_P1, *btnP1_cancel;
GtkWidget *btn1_P1_P1, *btn2_P1_P1,  *btn3_P1_P1, *btn4_P1_P1, *btn5_P1_P1, *btn6_P1_P1;
GtkWidget *btn1_P1_logo, *btn2_P1_logo, *btn3_P1_logo, *btn4_P1_logo, *btn5_P1_logo, *btn6_P1_logo, *pilihP1_logo;
GtkWidget *btn1_P1_lbl, *btn2_P1_lbl, *btn3_P1_lbl, *btn4_P1_lbl, *btn5_P1_lbl, *btn6_P1_lbl, *btnP1_cancel_lbl, *copywP1_lbl, *pilihP1_lbl1, *pilihP1_lbl2, *pilihP1_lbl3, *pilihP1_lbl4 , *pilihP1_lbl5, *pilihP2_lbl, *boxP1_lbl;

//window Kasbon
GtkWidget *windowKasbon;
GtkWidget *boxK, *boxK_grid, *boxK_b1, *boxK_b2;
GtkWidget *btn1_k_b2, *boxK_img;
GtkWidget *btn1_k_b2_lbl, *boxK_b1_lbl;

//window Kasbon
GtkWidget *windowError;
GtkWidget *boxE, *boxE_grid, *boxE_b1, *boxE_b2;
GtkWidget *btn1_E_b2;
GtkWidget *btn1_E_b2_lbl, *boxE_b1_lbl;

//====================================================================//
void pesawat();
void hotel();
void cuaca();
void kereta();
void jadwal();
void tukaruang();
void kapallaut();
void telepon();
void pengaturan();

void gtk_windowMain_init();
void gtk_windowMain_setAttrib();
void gtk_windowMain_connect();

static void start_windowMenu();
static void view_windowMenu();
static void close_windowMenu();
void gtk_windowMenu_init();
void gtk_windowMenu_setAttrib();
void gtk_windowMenu_connect();

static void start_windowTemp1();
static void close_windowTemp1();
static void view_windowTemp1();
void gtk_windowTemp1_init();
void gtk_windowTemp1_setAttrib();
void gtk_windowTemp1_connect();

static void start_windowTemp2();
static void close_windowTemp2();
static void view_windowTemp2();
void gtk_windowTemp2_init();
void gtk_windowTemp2_setAttrib();
void gtk_windowTemp2_connect();

static void start_windowTemp3();
static void close_windowTemp3();
static void view_windowTemp3();
void gtk_windowTemp3_init();
void gtk_windowTemp3_setAttrib();
void gtk_windowTemp3_connect();

static void start_windowPay();
static void close_windowPay();
static void view_windowPay();
void gtk_windowPay_init();
void gtk_windowPay_setAttrib();
void gtk_windowPay_connect();

static void start_windowKasbon();
static void close_windowKasbon();
static void view_windowKasbon();
static void gopay();
static void dana();
static void ovo();
static void linkaja();
static void shopeepay();
static void paylater();
void gtk_windowKasbon_init();
void gtk_windowKasbon_setAttrib();
void gtk_windowKasbon_connect();

static void start_windowError();
static void close_windowError();
static void view_windowError();
void gtk_windowError_init();
void gtk_windowError_setAttrib();
void gtk_windowError_connect();

void on_tujuan_entry1_changed();
void on_maskapai_entry1_changed();
void on_jam_entry1_changed();

void on_tujuan_entry2_changed();
void on_kereta_entry2_changed();
void on_jam_entry2_changed();

void on_tujuan_entry3_changed();
void on_kapal_entry3_changed();
void on_jam_entry3_changed();


char *IntToStr(int x);
void tamper1();

void gtk_builder_and_attrib_init();
void gtk_image_opt(GtkWidget *widget, char *fileName, int width, int hight, int margin_left);

//====================================================================//
//====================================================================//
int main(int argc, char **argv){

	gtk_init(&argc, &argv);
	//setup
	gtk_builder_and_attrib_init();
	
	gtk_windowMain_init();
	gtk_windowMain_connect();
	gtk_windowMain_setAttrib();

	
	start_windowMenu();
	start_windowTemp1();
	start_windowTemp2();
	start_windowTemp3();
	start_windowPay();
	start_windowKasbon();
	start_windowError();
	
	//start
	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowMain);
	g_object_unref(builder);
	gtk_main();
	return 0;
}
//====================================================================//
//====================================================================//

//====================================================================//
//====================================================================//

void gtk_builder_and_attrib_init(){
	builder=gtk_builder_new();
	gtk_builder_add_from_file (builder, "TRAVEJUL.glade", NULL);

	cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(cssProvider, "main.css", NULL);
}

void gtk_image_opt(GtkWidget *widget, char *fileName, int width, int hight, int margin_left){
	GdkPixbuf *my_img = gdk_pixbuf_new_from_file(fileName, NULL);
	my_img = gdk_pixbuf_scale_simple(my_img, width, hight, GDK_INTERP_BILINEAR);
	gtk_image_set_from_pixbuf(GTK_IMAGE(widget), my_img);
	gtk_widget_set_margin_start(widget, margin_left);
}

//====================================================================//

//Main window
void gtk_windowMain_init(){
	windowMain=GTK_WIDGET(gtk_builder_get_object(builder, "windowMain"));
	boxW=GTK_WIDGET(gtk_builder_get_object(builder, "boxW"));
	boxW_grid=GTK_WIDGET(gtk_builder_get_object(builder, "boxW_grid"));
	btn_hel=GTK_WIDGET(gtk_builder_get_object(builder, "btn_hel"));
	hello_logo=GTK_WIDGET(gtk_builder_get_object(builder, "hello_logo"));
	hello_box=GTK_WIDGET(gtk_builder_get_object(builder, "hello_box"));
	btn_lb_hel=GTK_WIDGET(gtk_builder_get_object(builder, "btn_lb_hel"));
}

void gtk_windowMain_setAttrib(){
	
	gtk_window_fullscreen(GTK_WINDOW(windowMain));

	gtk_widget_set_name(windowMain, "windowMain");
	gtk_widget_set_name(boxW, "boxW");
	gtk_widget_set_name(boxW_grid, "boxW_grid");
	gtk_widget_set_name(btn_hel, "btn_hel");
	gtk_widget_set_name(hello_logo, "hello_logo");
	gtk_widget_set_name(hello_box, "hello_box");
	gtk_widget_set_name(btn_lb_hel, "btn_lb_hel");
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	//set dimension
	int lbl_width = screenWidth/5;
	int lbl_hight = screenHight/10;
	gtk_widget_set_size_request(btn_hel, lbl_width, lbl_hight);
	
	int gspace_row = screenWidth/65; 
	int gspace_col = screenWidth/65;
	gtk_grid_set_row_spacing(GTK_GRID(boxW_grid), gspace_row);
	gtk_grid_set_column_spacing(GTK_GRID(boxW_grid), gspace_col);
	gtk_box_set_spacing(GTK_BOX(boxW), gspace_row);
	gtk_widget_set_margin_top(boxW, boxU_space);
	gtk_widget_set_margin_bottom(boxW, boxU_space);
	gtk_widget_set_margin_start(boxW, boxU_side_margin);
	gtk_widget_set_margin_end(boxW, boxU_side_margin);
}

void gtk_windowMain_connect(){
	g_signal_connect(windowMain, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btn_hel, "clicked", G_CALLBACK (view_windowMenu), NULL);
}


static void close_windowMain(){
	g_signal_connect(windowMain, "destroy", G_CALLBACK(gtk_main_quit), NULL);
}

//====================================================================//

//window Menu
static void start_windowMenu(){
	int argc; char **argv;
	gtk_init(&argc, &argv);
	gtk_builder_and_attrib_init();

	gtk_windowMenu_init();
	gtk_windowMenu_setAttrib();
	gtk_windowMenu_connect();

	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowMenu);
	gtk_widget_hide(windowMenu);
}

static void view_windowMenu(){
	gtk_widget_show(windowMenu);
	gtk_widget_hide(windowMain);
}

//====================================================================//

// window menu
void gtk_windowMenu_init(){
	windowMenu=GTK_WIDGET(gtk_builder_get_object(builder, "windowMenu"));
	menuC1=GTK_WIDGET(gtk_builder_get_object(builder, "boxU1_grid1"));
	boxU=GTK_WIDGET(gtk_builder_get_object(builder, "boxU"));
	boxU1=GTK_WIDGET(gtk_builder_get_object(builder, "boxU1"));
	boxU1_H1=GTK_WIDGET(gtk_builder_get_object(builder, "boxU1_H1"));
	boxU1_H2=GTK_WIDGET(gtk_builder_get_object(builder, "boxU1_H2"));
	boxU1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "boxU1_logo"));

	//button
	btn1_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U1"));
	btn2_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U1"));
	btn3_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U1"));
	btn4_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U1"));
	btn5_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U1"));
	btn6_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U1"));
	btn7_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U1"));
	btn8_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U1"));
	btn9_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn9_U1"));
	btnU1_cancel=GTK_WIDGET(gtk_builder_get_object(builder, "btnU1_cancel"));
	
	
	//button logo
	btn1_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U1_logo"));
	btn2_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U1_logo"));
	btn3_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U1_logo"));
	btn4_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U1_logo"));
	btn5_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U1_logo"));
	btn6_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U1_logo"));
	btn7_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U1_logo"));
	btn8_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U1_logo"));
	btn9_U1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn9_U1_logo"));
	

	//box
	btn1_U1_U1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U1_U1"));
	btn2_U1_U2=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U1_U2"));
	btn3_U1_U3=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U1_U3"));
	btn4_U1_U4=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U1_U4"));
	btn5_U1_U5=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U1_U5"));
	btn6_U1_U6=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U1_U6"));
	btn7_U1_U7=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U1_U7"));
	btn8_U1_U8=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U1_U8"));
	btn9_U1_U9=GTK_WIDGET(gtk_builder_get_object(builder, "btn9_U1_U9"));
	
	//label
	btn1_U1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_U1_lbl"));
	btn2_U1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_U1_lbl"));
	btn3_U1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_U1_lbl"));
	btn4_U1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_U1_lbl"));
	btn5_U1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_U1_lbl"));
	btn6_U1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_U1_lbl"));
	btn7_U1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn7_U1_lbl"));
	btn8_U1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn8_U1_lbl"));
	btn9_U1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn9_U1_lbl"));
	btnU1_cancel_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btnU1_cancel_lbl"));
	copywU1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "copywU1_lbl"));
}

void gtk_windowMenu_setAttrib(){
	gtk_window_fullscreen(GTK_WINDOW(windowMenu));
	
	gtk_widget_set_name (windowMenu, "windowMenu");
	gtk_widget_set_name (menuC1, "menuC1");
	gtk_widget_set_name (boxU, "boxU");
	gtk_widget_set_name (boxU1, "boxU1");
	gtk_widget_set_name (boxU1_H1, "boxU1_H1");
	gtk_widget_set_name (boxU1_H2, "boxU1_H2");
	gtk_widget_set_name (boxU1_logo, "boxU1_logo");

	//button
	gtk_widget_set_name (btn1_U1, "btn1_U1");
	gtk_widget_set_name (btn2_U1, "btn2_U1");
	gtk_widget_set_name (btn3_U1, "btn3_U1");
	gtk_widget_set_name (btn4_U1, "btn4_U1");
	gtk_widget_set_name (btn5_U1, "btn5_U1");
	gtk_widget_set_name (btn6_U1, "btn6_U1");
	gtk_widget_set_name (btn7_U1, "btn7_U1");
	gtk_widget_set_name (btn8_U1, "btn8_U1");
	gtk_widget_set_name (btn9_U1, "btn9_U1");
	gtk_widget_set_name (btnU1_cancel, "btnU1_cancel");

	//box
	gtk_widget_set_name (btn1_U1_U1, "btn1_U1_U1");
	gtk_widget_set_name (btn2_U1_U2, "btn2_U1_U2");
	gtk_widget_set_name (btn3_U1_U3, "btn3_U1_U3");
	gtk_widget_set_name (btn4_U1_U4, "btn4_U1_U4");
	gtk_widget_set_name (btn5_U1_U5, "btn5_U1_U5");
	gtk_widget_set_name (btn6_U1_U6, "btn6_U1_U6");
	gtk_widget_set_name (btn7_U1_U7, "btn7_U1_U7");
	gtk_widget_set_name (btn8_U1_U8, "btn8_U1_U8");
	gtk_widget_set_name (btn9_U1_U9, "btn9_U1_U9");

	//label
	gtk_widget_set_name(btn1_U1_lbl, "btn1_U1_lbl");
	gtk_widget_set_name(btn2_U1_lbl, "btn2_U1_lbl");
	gtk_widget_set_name(btn3_U1_lbl, "btn3_U1_lbl");
	gtk_widget_set_name(btn4_U1_lbl, "btn4_U1_lbl");
	gtk_widget_set_name(btn5_U1_lbl, "btn5_U1_lbl");
	gtk_widget_set_name(btn6_U1_lbl, "btn6_U1_lbl");
	gtk_widget_set_name(btn7_U1_lbl, "btn7_U1_lbl");
	gtk_widget_set_name(btn8_U1_lbl, "btn8_U1_lbl");
	gtk_widget_set_name(btn9_U1_lbl, "btn9_U1_lbl");
	gtk_widget_set_name(btnU1_cancel_lbl, "btnU1_cancel_lbl");
	gtk_widget_set_name(copywU1_lbl, "copywU1_lbl");
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	//set dimension
	int imWidth, imHight;
	int im_margin = screenHight/60;
	imWidth=imHight=screenWidth/15;
	gtk_image_opt(btn1_U1_logo, "img/logo_bt1.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn2_U1_logo, "img/logo_bt2.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn3_U1_logo, "img/logo_bt3.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn4_U1_logo, "img/logo_bt4.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn5_U1_logo, "img/logo_bt5.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn6_U1_logo, "img/logo_bt6.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn7_U1_logo, "img/logo_bt7.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn8_U1_logo, "img/logo_bt8.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn9_U1_logo, "img/logo_bt9.png", imWidth, imHight, im_margin);
	
	int imWidths, imHights;
	int im_margins = screenHight/60;
	imWidths=imHights=screenWidth/13;
	gtk_image_opt(boxU1_logo, "img/hello1.png", imWidths, imHights, im_margins);

	int lbl_width = screenWidth/8;
	int lbl_hight = screenHight/8;
	gtk_widget_set_size_request(btn1_U1_U1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn2_U1_U2, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn3_U1_U3, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn4_U1_U4, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn5_U1_U5, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn6_U1_U6, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn7_U1_U7, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn8_U1_U8, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn9_U1_U9, lbl_width, lbl_hight);
	
	
	int lbls_width = screenWidth/30;
	int lbls_hight = screenHight/30;
	gtk_widget_set_size_request(btnU1_cancel, lbls_width, lbls_hight);
	

	int gspace_row = screenWidth/65; 
	int gspace_col = screenWidth/65;
	gtk_grid_set_row_spacing(GTK_GRID(menuC1), gspace_row);
	gtk_grid_set_column_spacing(GTK_GRID(menuC1), gspace_col);
	gtk_box_set_spacing(GTK_BOX(boxU), gspace_row);
	gtk_widget_set_margin_top(boxU, boxU_space);
	gtk_widget_set_margin_bottom(boxU, boxU_space);
	gtk_widget_set_margin_start(boxU, boxU_side_margin);
	gtk_widget_set_margin_end(boxU, boxU_side_margin);
}

void gtk_windowMenu_connect(){
	g_signal_connect(windowMenu, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btnU1_cancel, "clicked", G_CALLBACK (close_windowMenu), NULL);
	g_signal_connect(btn1_U1, "clicked", G_CALLBACK (pesawat), NULL);
	//~ g_signal_connect(btn2_U1, "clicked", G_CALLBACK (hotel), NULL);
	//~ g_signal_connect(btn3_U1, "clicked", G_CALLBACK (cuaca), NULL);
	g_signal_connect(btn4_U1, "clicked", G_CALLBACK (kereta), NULL);
	//~ g_signal_connect(btn5_U1, "clicked", G_CALLBACK (jadwal), NULL);
	//~ g_signal_connect(btn6_U1, "clicked", G_CALLBACK (tukaruang), NULL);
	g_signal_connect(btn7_U1, "clicked", G_CALLBACK (kapallaut), NULL);
	//~ g_signal_connect(btn8_U1, "clicked", G_CALLBACK (telepon), NULL);
	//~ g_signal_connect(btn9_U1, "clicked", G_CALLBACK (pengaturan), NULL);
}

static void close_windowMenu(){
	gtk_main_quit();
}

//====================================================================//
//====================================================================//

// Window Temp1
static void start_windowTemp1(){
	int argc; char **argv;
	gtk_init(&argc, &argv);
	gtk_builder_and_attrib_init();

	gtk_windowTemp1_init();
	//gtk_windowTemp_setAttrib();
	gtk_windowTemp1_connect();

	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowTemp1);
	gtk_widget_hide(windowTemp1);
}

// Window Temp2
static void start_windowTemp2(){
	int argc; char **argv;
	gtk_init(&argc, &argv);
	gtk_builder_and_attrib_init();

	gtk_windowTemp2_init();
	//gtk_windowTemp_setAttrib();
	gtk_windowTemp2_connect();

	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowTemp2);
	gtk_widget_hide(windowTemp2);
}

// Window Temp3
static void start_windowTemp3(){
	int argc; char **argv;
	gtk_init(&argc, &argv);
	gtk_builder_and_attrib_init();

	gtk_windowTemp3_init();
	//gtk_windowTemp_setAttrib();
	gtk_windowTemp3_connect();

	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowTemp3);
	gtk_widget_hide(windowTemp3);
}

void pesawat(){
	view_windowTemp1(0,0);
}

//~ void hotel(){
	//~ view_windowTemp(1,1);
//~ }

//~ void cuaca(){
	//~ view_windowTemp(2,2);
//~ }

void kereta(){
	view_windowTemp2(3,3);
}

//~ void jadwal(){
	//~ view_windowTemp(4,4);
//~ }

//~ void tukaruang(){
	//~ view_windowTemp(5,5);
//~ }

void kapallaut(){
	view_windowTemp3(6,6);
}

//~ void telepon(){
	//~ view_windowTemp(7,7);
//~ }

//~ void pengaturan(){
	//~ view_windowTemp(8,8);
//~ }

static void view_windowTemp1(int num1, int num2){
	nummenu = num1;
	pilihmenu =  num2;
	gtk_windowTemp1_setAttrib();
	gtk_widget_show(windowTemp1);
	gtk_widget_hide(windowMenu);
}

static void view_windowTemp2(int num1, int num2){
	nummenu = num1;
	pilihmenu =  num2;
	gtk_windowTemp2_setAttrib();
	gtk_widget_show(windowTemp2);
	gtk_widget_hide(windowMenu);
}

static void view_windowTemp3(int num1, int num2){
	nummenu = num1;
	pilihmenu =  num2;
	gtk_windowTemp3_setAttrib();
	gtk_widget_show(windowTemp3);
	gtk_widget_hide(windowMenu);
}

//====================================================================//

// Window Temp1
void gtk_windowTemp1_init(){
	windowTemp1=GTK_WIDGET(gtk_builder_get_object(builder, "windowTemp1"));
	boxT1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT1"));
	boxT1_H1_H1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT1_H1_H1"));
	boxT1_1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT1_1"));
	boxT1_2=GTK_WIDGET(gtk_builder_get_object(builder, "boxT1_2"));
	MenuT1=GTK_WIDGET(gtk_builder_get_object(builder, "gridT1"));
	boxT1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "boxT1_logo"));

	//button
	btn_ok_T1=GTK_WIDGET(gtk_builder_get_object(builder, "btn_ok_T1"));
	btn_exit_T1=GTK_WIDGET(gtk_builder_get_object(builder, "btn_exit_T1"));
	btnbox1_temp1=GTK_WIDGET(gtk_builder_get_object(builder, "btnbox1_temp1"));
	btnbox2_temp1=GTK_WIDGET(gtk_builder_get_object(builder, "btnbox2_temp1"));
	btnbox3_temp1=GTK_WIDGET(gtk_builder_get_object(builder, "btnbox3_temp1"));
	
	//box
	boxT1_H1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT1_H1"));
	boxT1_H2=GTK_WIDGET(gtk_builder_get_object(builder, "boxT1_H2"));
	
	//entry
	tujuan_entry1=GTK_WIDGET(gtk_builder_get_object(builder, "tujuan_entry1"));
	maskapai_entry1=GTK_WIDGET(gtk_builder_get_object(builder, "maskapai_entry1"));
	jam_entry1=GTK_WIDGET(gtk_builder_get_object(builder, "jam_entry1"));
	

	//label
	maskapaiT1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "maskapaiT1_lbl"));
	tujuanT1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "tujuanT1_lbl"));
	jamT1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "jamT1_lbl"));
	box_T1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "box_T1_lbl"));
	btn_ok_T1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn_ok_T1_lbl"));
	btn_exit_T1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn_exit_T1_lbl"));
}

void gtk_windowTemp1_setAttrib(){
	gtk_window_fullscreen(GTK_WINDOW(windowTemp1));
	
	gtk_widget_set_name (windowTemp1, "windowTemp1");
	gtk_widget_set_name (boxT1, "boxT1");
	gtk_widget_set_name (boxT1_1, "boxT1_1");
	gtk_widget_set_name (boxT1_2, "boxT1_2");
	gtk_widget_set_name (boxT1_H1_H1, "boxT1_H1_H1");
	gtk_widget_set_name (boxT1_logo, "boxT1_logo");

	//button
	gtk_widget_set_name (btn_ok_T1, "btn_ok_T1");
	gtk_widget_set_name (btn_exit_T1, "btn_exit_T1");
	gtk_widget_set_name (btnbox1_temp1, "btnbox1_temp1");
	gtk_widget_set_name (btnbox2_temp1, "btnbox2_temp1");
	gtk_widget_set_name (btnbox3_temp1, "btnbox3_temp1");
	
	//box
	gtk_widget_set_name (boxT1_H1, "boxT1_H1");
	gtk_widget_set_name (boxT1_H2, "boxT1_H2");
	
	//entry
	gtk_widget_set_name (tujuan_entry1, "tujuan_entry1");
	gtk_widget_set_name (maskapai_entry1, "maskapai_entry1");
	gtk_widget_set_name (jam_entry1, "jam_entry1");

	//label
	gtk_widget_set_name(tujuanT1_lbl, "tujuanT1_lbl");
	gtk_widget_set_name(jamT1_lbl, "jamT1_lbl");
	gtk_widget_set_name(maskapaiT1_lbl, "maskapaiT1_lbl");
	gtk_widget_set_name(box_T1_lbl, "box_T1_lbl");
	gtk_widget_set_name(btn_ok_T1_lbl, "btn_ok_T1_lbl");
	gtk_widget_set_name(btn_exit_T1_lbl, "btn_exit_T1_lbl");
	
	//set dimension
	int imWidth, imHight;
	int im_margin = screenHight/60;
	imWidth=imHight=screenWidth/15;
	char imgstr[100];
	strcpy(imgstr, imgpilihan[nummenu]);
	gtk_image_opt(boxT1_logo, imgstr, imWidth, imHight, im_margin);
	
	char pilihstr1[100];
	char format1[100];
	strcpy(format1, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
	strcpy(pilihstr1, g_markup_printf_escaped (format1, pilihan[pilihmenu]));
	gtk_label_set_markup(GTK_LABEL(box_T1_lbl), (const gchar *) pilihstr1);
	
	data1 = 0;
	data2 = 0;
	data3 = 0;
	data4 = 0;
	data5 = 0;
	data6 = 0;
	data7 = 0;
	data8 = 0;
	data9 = 0;
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	//set dimension
	int lbl_width = screenWidth/15;
	int lbl_hight = screenHight/15;
	gtk_widget_set_size_request(jamT1_lbl, lbl_width, lbl_hight);
	gtk_widget_set_size_request(maskapaiT1_lbl, lbl_width, lbl_hight);
	gtk_widget_set_size_request(tujuanT1_lbl, lbl_width, lbl_hight);
	
	int lblc_width = screenWidth/10;
	int lblc_hight = screenHight/10;
	
	gtk_widget_set_size_request(box_T1_lbl, lblc_width, lblc_hight);
	
	int lbls_width = screenWidth/30;
	int lbls_hight = screenHight/30;
	gtk_widget_set_size_request(btn_exit_T1_lbl, lbls_width, lbls_hight);
	gtk_widget_set_size_request(btn_ok_T1_lbl, lbls_width, lbls_hight);
	
	int gspace_row = screenWidth/60; 
	int gspace_col = screenWidth/60;
	gtk_grid_set_row_spacing(GTK_GRID(MenuT1), gspace_row);
	gtk_grid_set_column_spacing(GTK_GRID(MenuT1), gspace_col);
	gtk_box_set_spacing(GTK_BOX(boxT1), gspace_row);
	gtk_widget_set_margin_top(boxT1, boxU_space);
	gtk_widget_set_margin_bottom(boxT1, boxU_space);
	gtk_widget_set_margin_start(boxT1, boxU_side_margin);
	gtk_widget_set_margin_end(boxT1, boxU_side_margin);
}

void gtk_windowTemp1_connect(){
	g_signal_connect(windowTemp1, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btn_ok_T1, "clicked", G_CALLBACK (tamper1), NULL);
	g_signal_connect(btn_exit_T1, "clicked", G_CALLBACK (close_windowTemp1), NULL);
}

static void close_windowTemp1(){
	gtk_widget_hide(windowTemp1);
	gtk_widget_show(windowMenu);
}


// Window Temp2
void gtk_windowTemp2_init(){
	windowTemp2=GTK_WIDGET(gtk_builder_get_object(builder, "windowTemp2"));
	boxT2=GTK_WIDGET(gtk_builder_get_object(builder, "boxT2"));
	boxT2_H1_H1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT2_H1_H1"));
	boxT2_1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT2_1"));
	boxT2_2=GTK_WIDGET(gtk_builder_get_object(builder, "boxT2_2"));
	MenuT2=GTK_WIDGET(gtk_builder_get_object(builder, "gridT2"));
	boxT2_logo=GTK_WIDGET(gtk_builder_get_object(builder, "boxT2_logo"));

	//button
	btn_ok_T2=GTK_WIDGET(gtk_builder_get_object(builder, "btn_ok_T2"));
	btn_exit_T2=GTK_WIDGET(gtk_builder_get_object(builder, "btn_exit_T2"));
	btnbox1_temp2=GTK_WIDGET(gtk_builder_get_object(builder, "btnbox1_temp2"));
	btnbox2_temp2=GTK_WIDGET(gtk_builder_get_object(builder, "btnbox2_temp2"));
	btnbox3_temp2=GTK_WIDGET(gtk_builder_get_object(builder, "btnbox3_temp2"));
	
	//box
	boxT2_H1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT2_H1"));
	boxT2_H2=GTK_WIDGET(gtk_builder_get_object(builder, "boxT2_H2"));
	
	//entry
	tujuan_entry2=GTK_WIDGET(gtk_builder_get_object(builder, "tujuan_entry2"));
	kereta_entry2=GTK_WIDGET(gtk_builder_get_object(builder, "kereta_entry2"));
	jam_entry2=GTK_WIDGET(gtk_builder_get_object(builder, "jam_entry2"));
	

	//label
	keretaT2_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "keretaT2_lbl"));
	tujuanT2_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "tujuanT2_lbl"));
	jamT2_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "jamT2_lbl"));
	box_T2_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "box_T2_lbl"));
	btn_ok_T2_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn_ok_T2_lbl"));
	btn_exit_T2_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn_exit_T2_lbl"));
}

void gtk_windowTemp2_setAttrib(){
	gtk_window_fullscreen(GTK_WINDOW(windowTemp2));
	
	gtk_widget_set_name (windowTemp2, "windowTemp2");
	gtk_widget_set_name (boxT2, "boxT2");
	gtk_widget_set_name (boxT2_1, "boxT2_1");
	gtk_widget_set_name (boxT2_2, "boxT2_2");
	gtk_widget_set_name (boxT2_H1_H1, "boxT2_H1_H1");
	gtk_widget_set_name (boxT2_logo, "boxT2_logo");

	//button
	gtk_widget_set_name (btn_ok_T2, "btn_ok_T2");
	gtk_widget_set_name (btn_exit_T2, "btn_exit_T2");
	gtk_widget_set_name (btnbox1_temp2, "btnbox1_temp2");
	gtk_widget_set_name (btnbox2_temp2, "btnbox2_temp2");
	gtk_widget_set_name (btnbox3_temp2, "btnbox3_temp2");
	
	//box
	gtk_widget_set_name (boxT2_H1, "boxT2_H1");
	gtk_widget_set_name (boxT2_H2, "boxT2_H2");
	
	//entry
	gtk_widget_set_name (tujuan_entry2, "tujuan_entry2");
	gtk_widget_set_name (kereta_entry2, "kereta_entry2");
	gtk_widget_set_name (jam_entry2, "jam_entry2");

	//label
	gtk_widget_set_name(tujuanT2_lbl, "tujuanT2_lbl");
	gtk_widget_set_name(jamT2_lbl, "jamT2_lbl");
	gtk_widget_set_name(keretaT2_lbl, "keretaT2_lbl");
	gtk_widget_set_name(box_T2_lbl, "box_T2_lbl");
	gtk_widget_set_name(btn_ok_T2_lbl, "btn_ok_T2_lbl");
	gtk_widget_set_name(btn_exit_T2_lbl, "btn_exit_T2_lbl");
	
	//set dimension
	int imWidth, imHight;
	int im_margin = screenHight/60;
	imWidth=imHight=screenWidth/15;
	char imgstr[100];
	strcpy(imgstr, imgpilihan[nummenu]);
	gtk_image_opt(boxT2_logo, imgstr, imWidth, imHight, im_margin);
	
	char pilihstr1[100];
	char format1[100];
	strcpy(format1, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
	strcpy(pilihstr1, g_markup_printf_escaped (format1, pilihan[pilihmenu]));
	gtk_label_set_markup(GTK_LABEL(box_T2_lbl), (const gchar *) pilihstr1);
	
	data1 = 0;
	data2 = 0;
	data3 = 0;
	data4 = 0;
	data5 = 0;
	data6 = 0;
	data7 = 0;
	data8 = 0;
	data9 = 0;
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	//set dimension
	int lbl_width = screenWidth/15;
	int lbl_hight = screenHight/15;
	gtk_widget_set_size_request(jamT2_lbl, lbl_width, lbl_hight);
	gtk_widget_set_size_request(keretaT2_lbl, lbl_width, lbl_hight);
	gtk_widget_set_size_request(tujuanT2_lbl, lbl_width, lbl_hight);
	
	int lblc_width = screenWidth/10;
	int lblc_hight = screenHight/10;
	
	gtk_widget_set_size_request(box_T2_lbl, lblc_width, lblc_hight);
	
	int lbls_width = screenWidth/30;
	int lbls_hight = screenHight/30;
	gtk_widget_set_size_request(btn_exit_T2_lbl, lbls_width, lbls_hight);
	gtk_widget_set_size_request(btn_ok_T2_lbl, lbls_width, lbls_hight);
	
	int gspace_row = screenWidth/60; 
	int gspace_col = screenWidth/60;
	gtk_grid_set_row_spacing(GTK_GRID(MenuT2), gspace_row);
	gtk_grid_set_column_spacing(GTK_GRID(MenuT2), gspace_col);
	gtk_box_set_spacing(GTK_BOX(boxT2), gspace_row);
	gtk_widget_set_margin_top(boxT2, boxU_space);
	gtk_widget_set_margin_bottom(boxT2, boxU_space);
	gtk_widget_set_margin_start(boxT2, boxU_side_margin);
	gtk_widget_set_margin_end(boxT2, boxU_side_margin);
}

void gtk_windowTemp2_connect(){
	g_signal_connect(windowTemp2, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btn_ok_T2, "clicked", G_CALLBACK (tamper1), NULL);
	g_signal_connect(btn_exit_T2, "clicked", G_CALLBACK (close_windowTemp2), NULL);
}

static void close_windowTemp2(){
	gtk_widget_hide(windowTemp2);
	gtk_widget_show(windowMenu);
}


// Window Temp3
void gtk_windowTemp3_init(){
	windowTemp3=GTK_WIDGET(gtk_builder_get_object(builder, "windowTemp3"));
	boxT3=GTK_WIDGET(gtk_builder_get_object(builder, "boxT3"));
	boxT3_H1_H1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT3_H1_H1"));
	boxT3_1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT3_1"));
	boxT3_2=GTK_WIDGET(gtk_builder_get_object(builder, "boxT3_2"));
	MenuT3=GTK_WIDGET(gtk_builder_get_object(builder, "gridT3"));
	boxT3_logo=GTK_WIDGET(gtk_builder_get_object(builder, "boxT3_logo"));

	//button
	btn_ok_T3=GTK_WIDGET(gtk_builder_get_object(builder, "btn_ok_T3"));
	btn_exit_T3=GTK_WIDGET(gtk_builder_get_object(builder, "btn_exit_T3"));
	btnbox1_temp3=GTK_WIDGET(gtk_builder_get_object(builder, "btnbox1_temp3"));
	btnbox2_temp3=GTK_WIDGET(gtk_builder_get_object(builder, "btnbox2_temp3"));
	btnbox3_temp3=GTK_WIDGET(gtk_builder_get_object(builder, "btnbox3_temp3"));
	
	//box
	boxT3_H1=GTK_WIDGET(gtk_builder_get_object(builder, "boxT3_H1"));
	boxT3_H2=GTK_WIDGET(gtk_builder_get_object(builder, "boxT3_H2"));
	
	//entry
	tujuan_entry3=GTK_WIDGET(gtk_builder_get_object(builder, "tujuan_entry3"));
	kapal_entry3=GTK_WIDGET(gtk_builder_get_object(builder, "kapal_entry3"));
	jam_entry3=GTK_WIDGET(gtk_builder_get_object(builder, "jam_entry3"));
	

	//label
	kapalT3_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "kapalT3_lbl"));
	tujuanT3_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "tujuanT3_lbl"));
	jamT3_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "jamT3_lbl"));
	box_T3_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "box_T3_lbl"));
	btn_ok_T3_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn_ok_T3_lbl"));
	btn_exit_T3_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn_exit_T3_lbl"));
}

void gtk_windowTemp3_setAttrib(){
	gtk_window_fullscreen(GTK_WINDOW(windowTemp3));
	
	gtk_widget_set_name (windowTemp3, "windowTemp3");
	gtk_widget_set_name (boxT3, "boxT3");
	gtk_widget_set_name (boxT3_1, "boxT3_1");
	gtk_widget_set_name (boxT3_2, "boxT3_2");
	gtk_widget_set_name (boxT3_H1_H1, "boxT3_H1_H1");
	gtk_widget_set_name (boxT3_logo, "boxT3_logo");

	//button
	gtk_widget_set_name (btn_ok_T3, "btn_ok_T3");
	gtk_widget_set_name (btn_exit_T3, "btn_exit_T3");
	gtk_widget_set_name (btnbox1_temp3, "btnbox1_temp3");
	gtk_widget_set_name (btnbox2_temp3, "btnbox2_temp3");
	gtk_widget_set_name (btnbox3_temp3, "btnbox3_temp3");
	
	//box
	gtk_widget_set_name (boxT3_H1, "boxT3_H1");
	gtk_widget_set_name (boxT3_H2, "boxT3_H2");
	
	//entry
	gtk_widget_set_name (tujuan_entry3, "tujuan_entry3");
	gtk_widget_set_name (kapal_entry3, "kapal_entry3");
	gtk_widget_set_name (jam_entry3, "jam_entry3");

	//label
	gtk_widget_set_name(tujuanT3_lbl, "tujuanT3_lbl");
	gtk_widget_set_name(jamT3_lbl, "jamT3_lbl");
	gtk_widget_set_name(kapalT3_lbl, "kapalT3_lbl");
	gtk_widget_set_name(box_T3_lbl, "box_T3_lbl");
	gtk_widget_set_name(btn_ok_T3_lbl, "btn_ok_T3_lbl");
	gtk_widget_set_name(btn_exit_T3_lbl, "btn_exit_T3_lbl");
	
	//set dimension
	int imWidth, imHight;
	int im_margin = screenHight/60;
	imWidth=imHight=screenWidth/15;
	char imgstr[100];
	strcpy(imgstr, imgpilihan[nummenu]);
	gtk_image_opt(boxT3_logo, imgstr, imWidth, imHight, im_margin);
	
	char pilihstr1[100];
	char format1[100];
	strcpy(format1, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
	strcpy(pilihstr1, g_markup_printf_escaped (format1, pilihan[pilihmenu]));
	gtk_label_set_markup(GTK_LABEL(box_T3_lbl), (const gchar *) pilihstr1);
	
	data1 = 0;
	data2 = 0;
	data3 = 0;
	data4 = 0;
	data5 = 0;
	data6 = 0;
	data7 = 0;
	data8 = 0;
	data9 = 0;
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	//set dimension
	int lbl_width = screenWidth/15;
	int lbl_hight = screenHight/15;
	gtk_widget_set_size_request(jamT3_lbl, lbl_width, lbl_hight);
	gtk_widget_set_size_request(kapalT3_lbl, lbl_width, lbl_hight);
	gtk_widget_set_size_request(tujuanT3_lbl, lbl_width, lbl_hight);
	
	int lblc_width = screenWidth/10;
	int lblc_hight = screenHight/10;
	
	gtk_widget_set_size_request(box_T3_lbl, lblc_width, lblc_hight);
	
	int lbls_width = screenWidth/30;
	int lbls_hight = screenHight/30;
	gtk_widget_set_size_request(btn_exit_T3_lbl, lbls_width, lbls_hight);
	gtk_widget_set_size_request(btn_ok_T3_lbl, lbls_width, lbls_hight);
	
	int gspace_row = screenWidth/60; 
	int gspace_col = screenWidth/60;
	gtk_grid_set_row_spacing(GTK_GRID(MenuT3), gspace_row);
	gtk_grid_set_column_spacing(GTK_GRID(MenuT3), gspace_col);
	gtk_box_set_spacing(GTK_BOX(boxT3), gspace_row);
	gtk_widget_set_margin_top(boxT3, boxU_space);
	gtk_widget_set_margin_bottom(boxT3, boxU_space);
	gtk_widget_set_margin_start(boxT3, boxU_side_margin);
	gtk_widget_set_margin_end(boxT3, boxU_side_margin);
}

void gtk_windowTemp3_connect(){
	g_signal_connect(windowTemp3, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btn_ok_T3, "clicked", G_CALLBACK (tamper1), NULL);
	g_signal_connect(btn_exit_T3, "clicked", G_CALLBACK (close_windowTemp3), NULL);
}

static void close_windowTemp3(){
	gtk_widget_hide(windowTemp3);
	gtk_widget_show(windowMenu);
}

//====================================================================//
//====================================================================//

//window Pay
static void start_windowPay(){
	int argc; char **argv;
	gtk_init(&argc, &argv);
	gtk_builder_and_attrib_init();

	gtk_windowPay_init();
	//gtk_windowPay_setAttrib();
	gtk_windowPay_connect();

	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowPay);
	gtk_widget_hide(windowPay);
}

// window Pay
void gtk_windowPay_init(){
	windowPay=GTK_WIDGET(gtk_builder_get_object(builder, "windowPay"));
	menuP1=GTK_WIDGET(gtk_builder_get_object(builder, "boxP1_grid1"));
	boxP=GTK_WIDGET(gtk_builder_get_object(builder, "boxP"));
	boxP1_H1=GTK_WIDGET(gtk_builder_get_object(builder, "boxP1_H1"));
	boxP1_H2=GTK_WIDGET(gtk_builder_get_object(builder, "boxP1_H2"));
	boxP1_H3=GTK_WIDGET(gtk_builder_get_object(builder, "boxP1_H3"));
	boxP1_H4=GTK_WIDGET(gtk_builder_get_object(builder, "boxP1_H4"));

	//button
	btn1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_P1"));
	btn2_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_P1"));
	btn3_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_P1"));
	btn4_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_P1"));
	btn5_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_P1"));
	btn6_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_P1"));
	btnP1_cancel=GTK_WIDGET(gtk_builder_get_object(builder, "btnP1_cancel"));
	
	//button logo
	btn1_P1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_P1_logo"));
	btn2_P1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_P1_logo"));
	btn3_P1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_P1_logo"));
	btn4_P1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_P1_logo"));
	btn5_P1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_P1_logo"));
	btn6_P1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_P1_logo"));
	pilihP1_logo=GTK_WIDGET(gtk_builder_get_object(builder, "pilihP1_logo"));

	//box
	btn1_P1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_P1_P1"));
	btn2_P1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_P1_P1"));
	btn3_P1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_P1_P1"));
	btn4_P1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_P1_P1"));
	btn5_P1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_P1_P1"));
	btn6_P1_P1=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_P1_P1"));

	//label
	btn1_P1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_P1_lbl"));
	btn2_P1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn2_P1_lbl"));
	btn3_P1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn3_P1_lbl"));
	btn4_P1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn4_P1_lbl"));
	btn5_P1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn5_P1_lbl"));
	btn6_P1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn6_P1_lbl"));
	btnP1_cancel_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btnP1_cancel_lbl"));
	pilihP1_lbl1=GTK_WIDGET(gtk_builder_get_object(builder, "pilihP1_lbl1"));
	pilihP1_lbl2=GTK_WIDGET(gtk_builder_get_object(builder, "pilihP1_lbl2"));
	pilihP1_lbl3=GTK_WIDGET(gtk_builder_get_object(builder, "pilihP1_lbl3"));
	pilihP1_lbl4=GTK_WIDGET(gtk_builder_get_object(builder, "pilihP1_lbl4"));
	pilihP1_lbl5=GTK_WIDGET(gtk_builder_get_object(builder, "pilihP1_lbl5"));
	pilihP2_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "pilihP2_lbl"));
	copywP1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "copywP1_lbl"));
	boxP1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "boxP1_lbl"));
}

void gtk_windowPay_setAttrib(){
	gtk_window_fullscreen(GTK_WINDOW(windowPay));

	gtk_widget_set_name (windowPay, "windowPay");
	
	gtk_widget_set_name (menuP1, "menuP1");
	gtk_widget_set_name (boxP, "boxP");
	gtk_widget_set_name (boxP1_H1, "boxP1_H1");
	gtk_widget_set_name (boxP1_H2, "boxP1_H2");
	gtk_widget_set_name (boxP1_H3, "boxP1_H3");
	gtk_widget_set_name (boxP1_H4, "boxP1_H4");

	//button
	gtk_widget_set_name (btn1_P1, "btn1_P1");
	gtk_widget_set_name (btn2_P1, "btn2_P1");
	gtk_widget_set_name (btn3_P1, "btn3_P1");
	gtk_widget_set_name (btn4_P1, "btn4_P1");
	gtk_widget_set_name (btn5_P1, "btn5_P1");
	gtk_widget_set_name (btn6_P1, "btn6_P1");
	gtk_widget_set_name (btnP1_cancel, "btnP1_cancel");

	//box
	gtk_widget_set_name (btn1_P1_P1, "btn1_P1_P1");
	gtk_widget_set_name (btn2_P1_P1, "btn2_P1_P1");
	gtk_widget_set_name (btn3_P1_P1, "btn3_P1_P1");
	gtk_widget_set_name (btn4_P1_P1, "btn4_P1_P1");
	gtk_widget_set_name (btn5_P1_P1, "btn5_P1_P1");
	gtk_widget_set_name (btn6_P1_P1, "btn6_P1_P1");

	//label
	gtk_widget_set_name(btn1_P1_lbl, "btn1_P1_lbl");
	gtk_widget_set_name(btn2_P1_lbl, "btn2_P1_lbl");
	gtk_widget_set_name(btn3_P1_lbl, "btn3_P1_lbl");
	gtk_widget_set_name(btn4_P1_lbl, "btn4_P1_lbl");
	gtk_widget_set_name(btn5_P1_lbl, "btn5_P1_lbl");
	gtk_widget_set_name(btn6_P1_lbl, "btn6_P1_lbl");
	gtk_widget_set_name(btnP1_cancel_lbl, "btnP1_cancel_lbl");
	gtk_widget_set_name(pilihP1_lbl1, "pilihP1_lbl1");
	gtk_widget_set_name(pilihP1_lbl2, "pilihP1_lbl2");
	gtk_widget_set_name(pilihP1_lbl3, "pilihP1_lbl3");
	gtk_widget_set_name(pilihP1_lbl4, "pilihP1_lbl4");
	gtk_widget_set_name(pilihP1_lbl5, "pilihP1_lbl5");
	gtk_widget_set_name(pilihP2_lbl, "pilihP2_lbl");
	gtk_widget_set_name(copywP1_lbl, "copywP1_lbl");
	gtk_widget_set_name(boxP1_lbl, "boxP1_lbl");
	
	gtk_widget_set_name (pilihP1_logo, "pilihP1_logo");
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	//set dimension
	int imWidth, imHight;
	int im_margin = screenHight/60;
	imWidth=imHight=screenWidth/15;
	gtk_image_opt(btn1_P1_logo, "img/logo_pay1.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn2_P1_logo, "img/logo_pay2.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn3_P1_logo, "img/logo_pay3.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn4_P1_logo, "img/logo_pay4.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn5_P1_logo, "img/logo_pay5.png", imWidth, imHight, im_margin);
	gtk_image_opt(btn6_P1_logo, "img/logo_pay6.png", imWidth, imHight, im_margin);
	
	char imgstr[100];
	strcpy(imgstr, imgpilihan[nummenu]);
	gtk_image_opt(pilihP1_logo, imgstr, imWidth, imHight, im_margin);
	
	char pilihstr1[100];
	char format1[100];
	strcpy(format1, "<span font_desc='monospace 17' foreground='#ffffff' ><b>%s</b></span>");
	strcpy(pilihstr1, g_markup_printf_escaped (format1, pilihan[pilihmenu]));
	gtk_label_set_markup(GTK_LABEL(pilihP1_lbl1), (const gchar *) pilihstr1);
	
	char pilihstr2[100];
	char format2[100];
	strcpy(format2, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
	strcpy(pilihstr2, g_markup_printf_escaped (format2, tmp1));
	gtk_label_set_markup(GTK_LABEL(pilihP1_lbl3), (const gchar *) pilihstr2);
	
	char pilihstr3[100];
	char format3[100];
	strcpy(format3, "<span font_desc='monospace 15' foreground='#ffffff' ><b>%s - </b></span>");
	strcpy(pilihstr3, g_markup_printf_escaped (format3, tmp2));
	gtk_label_set_markup(GTK_LABEL(pilihP1_lbl2), (const gchar *) pilihstr3);
	
	
	char pilihstr4[100];
	char format4[100];
	strcpy(format4, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
	strcpy(pilihstr4, g_markup_printf_escaped (format4, tmp3));
	gtk_label_set_markup(GTK_LABEL(pilihP1_lbl5), (const gchar *) pilihstr4);
	
	
	int lbl_width = screenWidth/9;
	int lbl_hight = screenHight/9;
	gtk_widget_set_size_request(btn1_P1_P1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn2_P1_P1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn3_P1_P1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn4_P1_P1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn5_P1_P1, lbl_width, lbl_hight);
	gtk_widget_set_size_request(btn6_P1_P1, lbl_width, lbl_hight);
	
	int lbls_width = screenWidth/30;
	int lbls_hight = screenHight/30;
	gtk_widget_set_size_request(btnP1_cancel, lbls_width, lbls_hight);

	int gspace_row = screenWidth/65; 
	int gspace_col = screenWidth/65;
	gtk_grid_set_row_spacing(GTK_GRID(menuP1), gspace_row);
	gtk_grid_set_column_spacing(GTK_GRID(menuP1), gspace_col);
	gtk_box_set_spacing(GTK_BOX(boxP), gspace_row);
	gtk_widget_set_margin_top(boxP, boxU_space);
	gtk_widget_set_margin_bottom(boxP, boxU_space);
	gtk_widget_set_margin_start(boxP, boxU_side_margin);
	gtk_widget_set_margin_end(boxP, boxU_side_margin);
}

void gtk_windowPay_connect(){
	g_signal_connect(windowPay, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btnP1_cancel, "clicked", G_CALLBACK (close_windowPay), NULL);
	g_signal_connect(btn1_P1, "clicked", G_CALLBACK (gopay), NULL);
	g_signal_connect(btn2_P1, "clicked", G_CALLBACK (dana), NULL);
	g_signal_connect(btn3_P1, "clicked", G_CALLBACK (ovo), NULL);
	g_signal_connect(btn4_P1, "clicked", G_CALLBACK (linkaja), NULL);
	g_signal_connect(btn5_P1, "clicked", G_CALLBACK (shopeepay), NULL);
	g_signal_connect(btn6_P1, "clicked", G_CALLBACK (paylater), NULL);
}

void close_windowPay(){
	gtk_widget_hide(windowPay);
}

//====================================================================//
//====================================================================//

// Window Kasbon
static void start_windowKasbon(){
	int argc; char **argv;
	gtk_init(&argc, &argv);
	gtk_builder_and_attrib_init();

	gtk_windowKasbon_init();
	gtk_windowKasbon_connect();

	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowKasbon);
	gtk_widget_hide(windowKasbon);
}

void gopay(){
	view_windowKasbon(0);
}

void dana(){
	view_windowKasbon(1);
}

void ovo(){
	view_windowKasbon(2);
}

void linkaja(){
	view_windowKasbon(3);
}

void shopeepay(){
	view_windowKasbon(4);
}

void paylater(){
	
}

static void view_windowKasbon(int num1){
	pay =  num1;
	gtk_windowKasbon_setAttrib();
	gtk_widget_show(windowKasbon);
	
}

// Window Kasbon
void gtk_windowKasbon_init(){
	windowKasbon=GTK_WIDGET(gtk_builder_get_object(builder, "windowKasbon"));
	boxK=GTK_WIDGET(gtk_builder_get_object(builder, "boxK"));
	boxK_grid=GTK_WIDGET(gtk_builder_get_object(builder, "boxK_grid"));

	//button
	btn1_k_b2=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_k_b2"));
	
	//box
	boxK_b1=GTK_WIDGET(gtk_builder_get_object(builder, "boxK_b1"));
	boxK_b2=GTK_WIDGET(gtk_builder_get_object(builder, "boxK_b2"));
	
	//logo
	boxK_img=GTK_WIDGET(gtk_builder_get_object(builder, "boxK_img"));

	//label
	boxK_b1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "boxK_b1_lbl"));
	btn1_k_b2_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_k_b2_lbl"));
}

void gtk_windowKasbon_setAttrib(){
	//~ gtk_window_fullscreen(GTK_WINDOW(windowKasbon));
	
	gtk_widget_set_name (windowKasbon, "windowKasbon");
	gtk_widget_set_name (boxK, "boxK");
	gtk_widget_set_name (boxK_grid, "boxK_grid");

	//button
	gtk_widget_set_name (btn1_k_b2, "btn1_k_b2");
	
	
	//box
	gtk_widget_set_name (boxK_b1, "boxK_b1");
	gtk_widget_set_name (boxK_b2, "boxK_b2");
	
	//logo
	gtk_widget_set_name (boxK_img, "boxK_img");

	//label
	gtk_widget_set_name(boxK_b1_lbl, "boxK_b1_lbl");
	gtk_widget_set_name(btn1_k_b2_lbl, "btn1_k_b2_lbl");
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	int imWidth, imHight;
	int im_margin = screenHight/20;
	imWidth=imHight=screenWidth/5;
	char imgstr[100];
	strcpy(imgstr, imgpay[pay]);
	gtk_image_opt(boxK_img, imgstr, imWidth, imHight, im_margin);
	
	//set dimension
	int lbl_width = screenWidth/30;
	int lbl_hight = screenHight/30;
	gtk_widget_set_size_request(boxK_b1_lbl, lbl_width, lbl_hight);
	
	int lbls_width = screenWidth/30;
	int lbls_hight = screenHight/30;
	gtk_widget_set_size_request(btn1_k_b2_lbl, lbls_width, lbls_hight);
	
	int gspace_row = screenWidth/60; 
	int gspace_col = screenWidth/60;
	gtk_grid_set_row_spacing(GTK_GRID(boxK_grid), gspace_row);
	gtk_grid_set_column_spacing(GTK_GRID(boxK_grid), gspace_col);
	gtk_box_set_spacing(GTK_BOX(boxK), gspace_row);
	gtk_widget_set_margin_top(boxK, boxU_space);
	gtk_widget_set_margin_bottom(boxK, boxU_space);
	gtk_widget_set_margin_start(boxK, boxU_side_margin);
	gtk_widget_set_margin_end(boxK, boxU_side_margin);
	

}

void gtk_windowKasbon_connect(){
	g_signal_connect(windowKasbon, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btn1_k_b2, "clicked", G_CALLBACK (close_windowKasbon), NULL);
}

static void close_windowKasbon(){
	gtk_widget_hide(windowKasbon);
	gtk_widget_show(windowPay);
}



//====================================================================//
//====================================================================//


// Window Error
static void start_windowError(){
	int argc; char **argv;
	gtk_init(&argc, &argv);
	gtk_builder_and_attrib_init();

	gtk_windowError_init();
	gtk_windowKasbon_setAttrib();
	gtk_windowError_connect();
	
	gtk_builder_connect_signals(builder, NULL);
	gtk_widget_show(windowError);
	gtk_widget_hide(windowError);
}

static void view_windowError(){
	gtk_widget_show(windowError);
	
}

// Window Kasbon
void gtk_windowError_init(){
	windowError=GTK_WIDGET(gtk_builder_get_object(builder, "windowError"));
	boxE=GTK_WIDGET(gtk_builder_get_object(builder, "boxE"));
	boxE_grid=GTK_WIDGET(gtk_builder_get_object(builder, "boxE_grid"));

	//button
	btn1_E_b2=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_E_b2"));
	
	//box
	boxE_b1=GTK_WIDGET(gtk_builder_get_object(builder, "boxE_b1"));
	boxE_b2=GTK_WIDGET(gtk_builder_get_object(builder, "boxE_b2"));

	//label
	boxE_b1_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "boxE_b1_lbl"));
	btn1_E_b2_lbl=GTK_WIDGET(gtk_builder_get_object(builder, "btn1_E_b2_lbl"));
}

void gtk_windowError_setAttrib(){
	//~ gtk_window_fullscreen(GTK_WINDOW(windowError));
	
	gtk_widget_set_name (windowError, "windowError");
	gtk_widget_set_name (boxE, "boxE");
	gtk_widget_set_name (boxE_grid, "boxE_grid");

	//button
	gtk_widget_set_name (btn1_E_b2, "btn1_E_b2");
	
	
	//box
	gtk_widget_set_name (boxE_b1, "boxE_b1");
	gtk_widget_set_name (boxE_b2, "boxE_b2");

	//label
	gtk_widget_set_name(boxE_b1_lbl, "boxE_b1_lbl");
	gtk_widget_set_name(btn1_E_b2_lbl, "btn1_E_b2_lbl");
	
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	//set dimension
	int lbl_width = screenWidth/30;
	int lbl_hight = screenHight/30;
	gtk_widget_set_size_request(boxE_b1_lbl, lbl_width, lbl_hight);
	
	int lbls_width = screenWidth/30;
	int lbls_hight = screenHight/30;
	gtk_widget_set_size_request(btn1_E_b2_lbl, lbls_width, lbls_hight);
	
	int gspace_row = screenWidth/60; 
	int gspace_col = screenWidth/60;
	gtk_grid_set_row_spacing(GTK_GRID(boxE_grid), gspace_row);
	gtk_grid_set_column_spacing(GTK_GRID(boxE_grid), gspace_col);
	gtk_box_set_spacing(GTK_BOX(boxE), gspace_row);
	gtk_widget_set_margin_top(boxE, boxU_space);
	gtk_widget_set_margin_bottom(boxE, boxU_space);
	gtk_widget_set_margin_start(boxE, boxU_side_margin);
	gtk_widget_set_margin_end(boxE, boxU_side_margin);
	

}

void gtk_windowError_connect(){
	g_signal_connect(windowError, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btn1_E_b2, "clicked", G_CALLBACK (close_windowError), NULL);
}

static void close_windowError(){
	gtk_widget_hide(windowError);
}

//====================================================================//
//====================================================================//



//====================================================================//
//====================================================================//

//====================================================================//
//====================================================================//

char *IntToStr(int x){
	char *str=(char *)malloc(10 * sizeof (char));
	sprintf(str, "%d", x);
	return str;
}

void on_tujuan_entry1_changed(GtkEntry *e){
	sprintf(tmp1, "%s", gtk_entry_get_text(e));
	data1 =gtk_combo_box_get_active(GTK_COMBO_BOX(btnbox1_temp1));
		
}
	
void on_maskapai_entry1_changed(GtkEntry *e){
	sprintf(tmp2, "%s", gtk_entry_get_text(e));
	data2 =gtk_combo_box_get_active(GTK_COMBO_BOX(btnbox2_temp1));
}
	
void on_jam_entry1_changed(GtkEntry *e){
	sprintf(tmp3, "%s", gtk_entry_get_text(e));
	data3 =gtk_combo_box_get_active(GTK_COMBO_BOX(btnbox3_temp1));
}

void on_tujuan_entry2_changed(GtkEntry *e){
	sprintf(tmp1, "%s", gtk_entry_get_text(e));
	data4 =gtk_combo_box_get_active(GTK_COMBO_BOX(btnbox1_temp2));
}
	
void on_kereta_entry2_changed(GtkEntry *e){
	sprintf(tmp2, "%s", gtk_entry_get_text(e));
	data5 =gtk_combo_box_get_active(GTK_COMBO_BOX(btnbox2_temp2));
}
	
void on_jam_entry2_changed(GtkEntry *e){
	sprintf(tmp3, "%s", gtk_entry_get_text(e));
	data6 =gtk_combo_box_get_active(GTK_COMBO_BOX(btnbox3_temp2));
}


void on_tujuan_entry3_changed(GtkEntry *e){
	sprintf(tmp1, "%s", gtk_entry_get_text(e));
	data7 =gtk_combo_box_get_active(GTK_COMBO_BOX(btnbox1_temp3));
}
	
void on_kapal_entry3_changed(GtkEntry *e){
	sprintf(tmp2, "%s", gtk_entry_get_text(e));
	data8 =gtk_combo_box_get_active(GTK_COMBO_BOX(btnbox2_temp3));
}
	
void on_jam_entry3_changed(GtkEntry *e){
	sprintf(tmp3, "%s", gtk_entry_get_text(e));
	data9 =gtk_combo_box_get_active(GTK_COMBO_BOX(btnbox3_temp3));
}

void tamper1(){
	
		// Pesawat ================================================================================
		if(data1 == 1 && data2 == 1 && data3 != 0) {
			total = 0;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data1 == 1 && data2 == 2 && data3 != 0) {
			total = 1;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data1 == 1 && data2 == 3 && data3 != 0) {
			total = 2;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data1 == 2 && data2 == 1 && data3 != 0) {
			total = 3;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data1 == 2 && data2 == 2 && data3 != 0) {
			total = 4;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data1 == 2 && data2 == 3 && data3 != 0) {
			total = 5;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data1 == 3 && data2 == 1 && data3 != 0) {
			total = 6;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data1 == 3 && data2 == 2 && data3 != 0) {
			total = 7;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data1 == 3 && data2 == 3 && data3 != 0) {
			total = 8;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
	
	
	//Kereta =============================================================================
		if(data4 == 1 && data5 == 1 && data6 != 0) {
			total = 9;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data4 == 1 && data5 == 2 && data6 != 0) {
			total = 10;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data4 == 1 && data5 == 3 && data6 != 0) {
			total = 11;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data4 == 2 && data5 == 1 && data6 != 0) {
			total = 12;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data4 == 2 && data5 == 2 && data6 != 0) {
			total = 13;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data4 == 2 && data5 == 3 && data6 != 0) {
			total = 14;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data4 == 3 && data5 == 1 && data6 != 0) {
			total = 15;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data4 == 3 && data5 == 2 && data6 != 0) {
			total = 16;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data4 == 3 && data5 == 3 && data6 != 0) {
			total = 17;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		
		
		//Kapal laut =============================================================================
		if(data7 == 1 && data8 == 1 && data9 != 0) {
			total = 18;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data7 == 1 && data8 == 2 && data9 != 0) {
			total = 19;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data7 == 1 && data8 == 3 && data9 != 0) {
			total = 20;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data7 == 2 && data8 == 1 && data9 != 0) {
			total = 21;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data7 == 2 && data8 == 2 && data9 != 0) {
			total = 22;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data7 == 2 && data8 == 3 && data9 != 0) {
			total = 23;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data7 == 3 && data8 == 1 && data9 != 0) {
			total = 24;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data7 == 3 && data8 == 2 && data9 != 0) {
			total = 25;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
		if(data7 == 3 && data8 == 3 && data9 != 0) {
			total = 26;
			gtk_windowPay_setAttrib();
			gtk_widget_show(windowPay);
			char pilihstr5[100];
			char format5[100];
			strcpy(format5, "<span font_desc='monospace 15' foreground='#ffffff' >%s</span>");
			strcpy(pilihstr5, g_markup_printf_escaped (format5, harga1[total]));
			gtk_label_set_markup(GTK_LABEL(pilihP2_lbl), (const gchar *) pilihstr5);
		}
}

//====================================================================//
//====================================================================//
