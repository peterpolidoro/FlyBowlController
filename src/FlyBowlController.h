// ----------------------------------------------------------------------------
// FlyBowlController.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef FLY_BOWL_CONTROLLER_H
#define FLY_BOWL_CONTROLLER_H
#include <ArduinoJson.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <ConstantVariable.h>
#include <Functor.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>
#include <DigitalController.h>
#include <BacklightController.h>

#include "FlyBowlController/Constants.h"


class FlyBowlController : public BacklightController
{
public:
  FlyBowlController();
  virtual void setup();

  void setIrBacklightOnAtPower(size_t fly_bowl,
    long power);
  void setIrBacklightOn(size_t fly_bowl);
  void setIrBacklightOff(size_t fly_bowl);
  void setIrBacklightsOnAtPower(long power);
  void setIrBacklightsOn();
  void setIrBacklightsOff();

  void setVisibleBacklightOnAtPower(size_t fly_bowl,
    long power);
  void setVisibleBacklightOn(size_t fly_bowl);
  void setVisibleBacklightOff(size_t fly_bowl);
  void setVisibleBacklightsOnAtPower(long power);
  void setVisibleBacklightsOn();
  void setVisibleBacklightsOff();

  int addVisibleBacklightsPwm(long power,
    long delay,
    long period,
    long on_duration,
    long count);

private:
  modular_server::Property properties_[fly_bowl_controller::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[fly_bowl_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[fly_bowl_controller::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[fly_bowl_controller::constants::CALLBACK_COUNT_MAX];

  size_t getFlyBowlCount();

  void setFanOn(size_t fly_bowl);
  void setFanOff(size_t fly_bowl);

  void setIndicatorOn(size_t fly_bowl);
  void setIndicatorOff(size_t fly_bowl);

  // Handlers
  void setFlyBowlEnabledHandler(size_t fly_bowl);
  void setIrBacklightsOnAtPowerHandler();
  void setIrBacklightsOnHandler(modular_server::Pin * pin_ptr);
  void setIrBacklightsOffHandler(modular_server::Pin * pin_ptr);
  void setVisibleBacklightsOnAtPowerHandler();
  void setVisibleBacklightsOnHandler(modular_server::Pin * pin_ptr);
  void setVisibleBacklightsOffHandler(modular_server::Pin * pin_ptr);
  void addVisibleBacklightsPwmHandler();

  void startVisibleBacklightsPwmHandler(int pwm_index);
  void stopVisibleBacklightsPwmHandler(int pwm_index);
  void setVisibleBacklightsOnAtPowerHandler(int pwm_index);
  void setVisibleBacklightsOffHandler(int pwm_index);

};

#endif