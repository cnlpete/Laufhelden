/*
 * Copyright (C) 2017 Jens Drescher, Germany
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "settings.h"
#include "device.h"

Settings::Settings(QObject *parent) :
    QObject(parent)
{
    m_settings = new QSettings("harbour-laufhelden", "harbour-laufhelden");
}

int Settings::updateInterval() const
{
    return m_settings->value("positioning/updateInterval", 1000).toInt();
}
void Settings::setUpdateInterval(int updateInterval)
{
    m_settings->setValue("positioning/updateInterval", updateInterval);
    emit updateIntervalChanged();
}

QString Settings::hrmdevice() const
{
        return m_settings->value("hrm/hrmdevice", ",").toString();
}
void Settings::setHrmdevice(QString hrmdevice)
{
    m_settings->setValue("hrm/hrmdevice", hrmdevice);
}

bool Settings::recordPagePortrait() const
{
    return m_settings->value("generalsettings/recordpageportrait", true).toBool();
}
void Settings::setRecordPagePortrait(bool recordPagePortrait)
{
    m_settings->setValue("generalsettings/recordpageportrait", recordPagePortrait);
}

QString Settings::workoutType() const
{
    return m_settings->value("recordsettings/workoutType", "running").toString();
}
void Settings::setWorkoutType(QString workoutType)
{
    m_settings->setValue("recordsettings/workoutType", workoutType);
}

bool Settings::useHRMdevice() const
{
    return m_settings->value("hrm/useHRMdevice", false).toBool();
}
void Settings::setUseHRMdevice(bool useHRMdevice)
{
     m_settings->setValue("hrm/useHRMdevice", useHRMdevice);
}

bool Settings::useHRMservice() const
{
    return m_settings->value("hrm/useHRMservice", false).toBool();
}
void Settings::setUseHRMservice(bool useHRMservice)
{
     m_settings->setValue("hrm/useHRMservice", useHRMservice);
}

bool Settings::disableScreenBlanking() const
{
    return m_settings->value("recordsettings/disableScreenBlanking", false).toBool();
}
void Settings::setDisableScreenBlanking(bool disableScreenBlanking)
{
     m_settings->setValue("recordsettings/disableScreenBlanking", disableScreenBlanking);
}
bool Settings::showMapRecordPage() const
{
    return m_settings->value("recordsettings/showMapRecordPage", true).toBool();
}
void Settings::setShowMapRecordPage(bool showMapRecordPage)
{
     m_settings->setValue("recordsettings/showMapRecordPage", showMapRecordPage);
}
QString Settings::thresholds() const
{
    return m_settings->value("recordsettings/thresholds", "Thresholds off,true,false,0,false,0,false,0,false,0|Wettkampf 10km,false,true,183,false,133,true,5.0,true,4.5|Training GA 1,false,true,141,true,130,false,6.2,false,3.2").toString();
}
void Settings::setThresholds(QString thresholds)
{
    m_settings->setValue("recordsettings/thresholds", thresholds);
}
bool Settings::enableLogFile() const
{
    return m_settings->value("generalsettings/enableLogFile", false).toBool();
}
void Settings::setEnableLogFile(bool enableLogFile)
{
     m_settings->setValue("generalsettings/enableLogFile", enableLogFile);
}
int Settings::displayMode() const
{
    return m_settings->value("recordsettings/displayMode", 3).toInt();
}
void Settings::setDisplayMode(int displayMode)
{
    m_settings->setValue("recordsettings/displayMode", displayMode);
}
bool Settings::showBorderLines() const
{
    return m_settings->value("generalsettings/showBorderLines", true).toBool();
}
void Settings::setShowBorderLines(bool showBorderLines)
{
     m_settings->setValue("generalsettings/showBorderLines", showBorderLines);
}
QString Settings::valueFields() const
{
    return m_settings->value("recordsettings/valueFields", "3,4,1,2,7,8|5,6,1,2,7,8|5,6,1,2,7,8|3,4,1,2,7,8|5,6,1,2,7,8").toString();
}
void Settings::setValueFields(QString valueFields)
{
    m_settings->setValue("recordsettings/valueFields", valueFields);
}
bool Settings::enableAutosave() const
{
    return m_settings->value("generalsettings/enableAutosave", false).toBool();
}
void Settings::setEnableAutosave(bool enableAutosave)
{
     m_settings->setValue("generalsettings/enableAutosave", enableAutosave);
}
bool Settings::autoNightMode() const
{
    return m_settings->value("generalsettings/autoNightMode", true).toBool();
}
void Settings::setAutoNightMode(bool autoNightMode)
{
     m_settings->setValue("generalsettings/autoNightMode", autoNightMode);
}
int Settings::mapMode() const
{
    return m_settings->value("mapsettings/mapMode", 0).toInt();
}
void Settings::setMapMode(int mapMode)
{
    m_settings->setValue("mapsettings/mapMode", mapMode);
}

bool Settings::mapShowOnly4Fields() const
{
    return m_settings->value("mapsettings/mapShowOnly4Fields", true).toBool();
}
void Settings::setmapShowOnly4Fields(bool mapShowOnly4Fields)
{
     m_settings->setValue("mapsettings/mapShowOnly4Fields", mapShowOnly4Fields);
}

QString Settings::valueCoverFields() const
{
    return m_settings->value("generalsettings/valueCoverFields", "10,8,3").toString();
}
void Settings::setValueCoverFields(QString valueCoverFields)
{
    m_settings->setValue("generalsettings/valueCoverFields", valueCoverFields);
}

bool Settings::enablePebble() const
{
    return m_settings->value("pebblesettings/enablePebble", false).toBool();
}
void Settings::setEnablePebble(bool enablePebble)
{
     m_settings->setValue("pebblesettings/enablePebble", enablePebble);
}
QString Settings::valuePebbleFields() const
{
    return m_settings->value("pebblesettings/valuePebbleFields", "10,8,3").toString();
}
void Settings::setValuePebbleFields(QString valuePebbleFields)
{
    m_settings->setValue("pebblesettings/valuePebbleFields", valuePebbleFields);
}
QString Settings::pebbleIDstring() const
{
    return m_settings->value("pebblesettings/pebbleIDstring", "").toString();
}
void Settings::setPebbleIDstring(QString pebbleIDstring)
{
    m_settings->setValue("pebblesettings/pebbleIDstring", pebbleIDstring);
}

QString Settings::mapStyle() const
{
    return m_settings->value("mapsettings/mapStyle", "mapbox://styles/mapbox/outdoors-v10").toString();
}
void Settings::setMapStyle(QString mapStyle)
{
    m_settings->setValue("mapsettings/mapStyle", mapStyle);
}

int Settings::mapCache() const
{
    return m_settings->value("mapsettings/mapCache", 50).toInt();
}
void Settings::setMapCache(int mapCache)
{
    m_settings->setValue("mapsettings/mapCache", mapCache);
}
int Settings::measureSystem() const
{
    return m_settings->value("generalsettings/measureSystem", 0).toInt();
}
void Settings::setMeasureSystem(int measureSystem)
{
    m_settings->setValue("generalsettings/measureSystem", measureSystem);
}

bool Settings::mapDisableRecordPage() const
{
    return m_settings->value("mapsettings/mapDisableRecordPage", false).toBool();
}
void Settings::setMapDisableRecordPage(bool mapDisableRecordPage)
{
     m_settings->setValue("mapsettings/mapDisableRecordPage", mapDisableRecordPage);
}

QString Settings::workoutTypeMainPage() const
{
    return m_settings->value("generalsettings/workoutTypeMainPage", "allworkouts").toString();
}
void Settings::setWorkoutTypeMainPage(QString workoutTypeMainPage)
{
    m_settings->setValue("generalsettings/workoutTypeMainPage", workoutTypeMainPage);
}

//Voice output
int Settings::voiceLanguage() const
{
    return m_settings->value("generalsettings/voiceLanguage", 0).toInt();
}
void Settings::setVoiceLanguage(int voiceLanguage)
{
    m_settings->setValue("generalsettings/voiceLanguage", voiceLanguage);
}
bool Settings::voicePauseMusic() const
{
    return m_settings->value("generalsettings/voicePauseMusic", true).toBool();
}
void Settings::setVoicePauseMusic(bool voicePauseMusic)
{
     m_settings->setValue("generalsettings/voicePauseMusic", voicePauseMusic);
}
bool Settings::voiceStartEndWorkout() const
{
    return m_settings->value("generalsettings/voiceStartEndWorkout", true).toBool();
}
void Settings::setVoiceStartEndWorkout(bool voiceStartEndWorkout)
{
     m_settings->setValue("generalsettings/voiceStartEndWorkout", voiceStartEndWorkout);
}
bool Settings::voicePauseContinueWorkout() const
{
    return m_settings->value("generalsettings/voicePauseContinueWorkout", true).toBool();
}
void Settings::setVoicePauseContinueWorkout(bool voicePauseContinueWorkout)
{
     m_settings->setValue("generalsettings/voicePauseContinueWorkout", voicePauseContinueWorkout);
}
bool Settings::voiceGPSConnectLost() const
{
    return m_settings->value("generalsettings/voiceGPSConnectLost", true).toBool();
}
void Settings::setVoiceGPSConnectLost(bool voiceGPSConnectLost)
{
     m_settings->setValue("generalsettings/voiceGPSConnectLost", voiceGPSConnectLost);
}

//Cyclic voice output
bool Settings::voiceCycDistanceEnable() const
{
    return m_settings->value("voicecyclesettings/voiceCycDistanceEnable", false).toBool();
}
void Settings::setVoiceCycDistanceEnable(bool voiceCycDistanceEnable)
{
     m_settings->setValue("voicecyclesettings/voiceCycDistanceEnable", voiceCycDistanceEnable);
}
double Settings::voiceCycDistance() const
{
    return m_settings->value("voicecyclesettings/voiceCycDistance", 1.0).toDouble();
}
void Settings::setVoiceCycDistance(double voiceCycDistance)
{
    m_settings->setValue("voicecyclesettings/voiceCycDistance", voiceCycDistance);
}
QString Settings::voiceCycDistanceFields() const
{
    return m_settings->value("voicecyclesettings/voiceCycDistanceFields", "9,8,3,5").toString();
}
void Settings::setVoiceCycDistanceFields(QString voiceCycDistanceFields)
{
    m_settings->setValue("voicecyclesettings/voiceCycDistanceFields", voiceCycDistanceFields);
}
bool Settings::voiceCycDurationEnable() const
{
    return m_settings->value("voicecyclesettings/voiceCycDurationEnable", false).toBool();
}
void Settings::setVoiceCycDurationEnable(bool voiceCycDurationEnable)
{
     m_settings->setValue("voicecyclesettings/voiceCycDurationEnable", voiceCycDurationEnable);
}
int Settings::voiceCycDuration() const
{
    return m_settings->value("voicecyclesettings/voiceCycDuration", 60).toInt();
}
void Settings::setVoiceCycDuration(int voiceCycDuration)
{
    m_settings->setValue("voicecyclesettings/voiceCycDuration", voiceCycDuration);
}
QString Settings::voiceCycDurationFields() const
{
    return m_settings->value("voicecyclesettings/voiceCycDurationFields", "9,8,5,3").toString();
}
void Settings::setVoiceCycDurationFields(QString voiceCycDurationFields)
{
    m_settings->setValue("voicecyclesettings/voiceCycDurationFields", voiceCycDurationFields);
}
bool Settings::voiceCycDistanceHeadlineEnable() const
{
    return m_settings->value("voicecyclesettings/voiceCycDistanceHeadlineEnable", true).toBool();
}
void Settings::setVoiceCycDistanceHeadlineEnable(bool voiceCycDistanceHeadlineEnable)
{
     m_settings->setValue("voicecyclesettings/voiceCycDistanceHeadlineEnable", voiceCycDistanceHeadlineEnable);
}
bool Settings::voiceCycDurationHeadlineEnable() const
{
    return m_settings->value("voicecyclesettings/voiceCycDurationHeadlineEnable", true).toBool();
}
void Settings::setVoiceCycDurationHeadlineEnable(bool voiceCycDurationHeadlineEnable)
{
     m_settings->setValue("voicecyclesettings/voiceCycDurationHeadlineEnable", voiceCycDurationHeadlineEnable);
}

//Sports-Tracker.com Sharing functions
void Settings::setStUsername(QString username)
{
    return m_settings->setValue("sportstracker/username", username);
}
QString Settings::stUsername() const
{
    return m_settings->value("sportstracker/username").toString();
}

void Settings::setStPassword(QString password)
{
    return m_settings->setValue("sportstracker/password", password);
}
QString Settings::stPassword() const
{
    return m_settings->value("sportstracker/password").toString();
}

void Settings::setStAutoUpload(bool stAutoUpload)
{
     m_settings->setValue("sportstracker/autoupload", stAutoUpload);
}

bool Settings::stAutoUpload() const
{
    return m_settings->value("sportstracker/autoupload", true).toBool();
}

void Settings::setStSharing(int stSharing)
{
     m_settings->setValue("sportstracker/sharing", stSharing);
}

int Settings::stSharing() const
{
    return m_settings->value("sportstracker/sharing", 0).toInt(); //Defaults Private option = 0
}

void Settings::setStSessionkey(QString key)
{
    return m_settings->setValue("sportstracker/sessionkey", key);
}

QString Settings::stSessionkey() const
{
    return m_settings->value("sportstracker/sessionkey").toString();
}

int Settings::bluetoothType() const
{
    return m_settings->value("hrm/bluetoothtype", Device::BLEPUBLIC).toInt();
}
void Settings::setBluetoothType(int stBluetoothType)
{
    m_settings->setValue("hrm/bluetoothtype",stBluetoothType);
}
