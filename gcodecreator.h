#ifndef _STLCREATOR_H_
#define _STLCREATOR_H_

#include <KIO/ThumbCreator>
#include <KIO/ThumbnailCreator>



class GcodeCreator : public ThumbCreator
{
    public:
        GcodeCreator();
        ~GcodeCreator() override;

        bool create(const QString &path, int width, int height, QImage &img) override;

};

void clean(void *info);

#endif
