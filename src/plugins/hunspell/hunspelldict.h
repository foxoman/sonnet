/**
 * kspell_aspelldict.h
 *
 * Copyright (C)  2009  Montel Laurent <montel@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */
#ifndef KSPELL_HUNSPELLDICT_H
#define KSPELL_HUNSPELLDICT_H

#include "spellerplugin_p.h"
#include "hunspell/hunspell.hxx"

#ifndef HUNSPELL_MAIN_DICT_PATH
#ifdef Q_OS_MAC
#define HUNSPELL_MAIN_DICT_PATH "/System/Library/Spelling"
#else
#define HUNSPELL_MAIN_DICT_PATH "/usr/share/hunspell"
#endif
#endif

class HunspellDict : public Sonnet::SpellerPlugin
{
public:
    explicit HunspellDict(const QString &lang, QString path);
    ~HunspellDict();
    bool isCorrect(const QString &word) const Q_DECL_OVERRIDE;

    QStringList suggest(const QString &word) const Q_DECL_OVERRIDE;

    bool storeReplacement(const QString &bad,
                                  const QString &good) Q_DECL_OVERRIDE;

    bool addToPersonal(const QString &word) Q_DECL_OVERRIDE;
    bool addToSession(const QString &word) Q_DECL_OVERRIDE;

private:
    QByteArray toDictEncoding(const QString &word) const;

    Hunspell *m_speller;
    QTextCodec *m_codec;
};

#endif
