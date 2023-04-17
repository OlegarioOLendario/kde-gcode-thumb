#include "gcodecreator.h"

#include <QFile>
#include <QImage>
#include <QtDebug>
#include <QString>


extern "C"
{
    Q_DECL_EXPORT ThumbCreator *new_creator()
    {
        return new GcodeCreator();
    }
};

GcodeCreator::GcodeCreator() = default;

GcodeCreator::~GcodeCreator() = default;

bool GcodeCreator::create(const QString &path, int width, int height, QImage &img)
{
    QFile f(path);
    if(!f.open(QIODevice::ReadOnly)) {
        return false;
    }

    QString text, tmp;
    QTextStream ts(&f);

bool tbnail = false;
    while(ts.readLineInto(&tmp)){

        if(!tmp.contains("thumbnail begin") && !tbnail)
          tmp.clear();

        else if(tbnail)
          text.append(tmp);

        else if(tmp.contains("thumbnail begin") && !tbnail){
          tbnail = true;
          tmp.clear();
        }

        if(tmp.contains("thumbnail end") )
          break;
    }

    text.remove("; ");
    text.remove("thumbnail end");


    QImage _img;
    if(!_img.loadFromData( QByteArray::fromBase64(text.toUtf8()) )) return false;
    img = _img.scaled(width, height);


    return true;
}

