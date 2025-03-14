#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modbus.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::initialize()
{
    modbus_t *ctx;
    uint16_t tab_reg[32];
    int rc;
    int i;

    // 创建 Modbus TCP 上下文
    ctx = modbus_new_tcp("127.0.0.1", 1502);
    if (ctx == NULL) {
        fprintf(stderr, "Unable to create the libmodbus context\n");
        return -1;
    }

    // 设置调试模式
    modbus_set_debug(ctx, TRUE);

    // 连接到服务器
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return -1;
    }

    // 读取保持寄存器
    rc = modbus_read_registers(ctx, 0, 10, tab_reg);
    if (rc == -1) {
        fprintf(stderr, "Failed to read registers: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return -1;
    }

    // 打印读取到的寄存器值
    for (i = 0; i < rc; i++) {
        printf("reg[%d]=%d (0x%X)\n", i, tab_reg[i], tab_reg[i]);
    }

    // 关闭连接并释放资源
    modbus_close(ctx);
    modbus_free(ctx);
}

