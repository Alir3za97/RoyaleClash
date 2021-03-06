//
// Created by alireza on 7/9/16.
//

#ifndef ROYALECLASH_SETTINGS_H
#define ROYALECLASH_SETTINGS_H
#include <QString>
#include <QSize>

struct Setting {
    static QString outmusic;
    static QString inmusic;
    static int default_music_volume;
    static bool is_muted;

    static QSize window_size;

    static QString startIcon;
    static QString picturesPath[15];
    static QString cardNames[15];

    static int elixir_costs[15];
};

#endif //ROYALECLASH_SETTINGS_H
