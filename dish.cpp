#include "data.h"
#include "ui_data.h"

QString sourceFileName ="dish_data.txt";

Dish::Dish(){}
void Dish::setDish()
{

}
void Dish::deleteDish()
{
    QFile sourceFile(sourceFileName);
    int lineToDelete=num;
    QString tempFileName = "temp.txt";  // 定义一个临时文件名
    QFile tempFile(tempFileName);

    // 打开源文件以读取
    if (!sourceFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开源文件：" << sourceFileName;
        return;
    }

    // 打开临时文件以写入
    if (!tempFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法创建临时文件：" << tempFileName;
        sourceFile.close();
        return;
    }

    QTextStream in(&sourceFile);
    QTextStream out(&tempFile);
    int currentLine = 0;

    // 逐行读取源文件内容，并写入临时文件
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (currentLine != lineToDelete) {  // 跳过要删除的行
            out << line << "\n";            // 写入临时文件
        }
        currentLine++;
    }

    sourceFile.close();  // 关闭源文件
    tempFile.close();    // 关闭临时文件

    // 删除原文件
    if (!QFile::remove(sourceFileName)) {
        qDebug() << "删除原文件失败：" << sourceFileName;
        return;
    }

    // 将临时文件重命名为原文件名
    if (!QFile::rename(tempFileName, sourceFileName)) {
        qDebug() << "重命名临时文件失败：" << tempFileName;
        return;
    }

    qDebug() << "第" << lineToDelete + 1 << "行已删除";
}



void Dish::saveDish()
{
    QFile file(sourceFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件进行写入";
        return;
    }

    QTextStream out(&file);
    out<<name<<","<<amount<<","<<price<<","<<pixlocation<<","<<num<<"\n";

   file.close();

}
