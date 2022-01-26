//  CTello is a C++ library to interact with the DJI Ryze Tello Drone
//  Copyright (C) 2020 Carlos Perez-Lopez
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>
//
//  You can contact the author via carlospzlz@gmail.com

#include <iostream>

#include "ctello.h"
#include <unistd.h>


using ctello::Tello;

int main()
{
    Tello tello1 = Tello(false, "tello1", "192.168.48.6", 10000, 10001);
    Tello tello2 = Tello(false, "tello2", "192.168.45.145", 10002, 10003);

//    if (!tello1.Bind(10000,10001))
//    {
//        return 0;
//    }
//    if (!tello2.Bind(10002,10003)){
//        return 0;
//    }
    int tello1Battery = tello1.GetBatteryState(50);
    int tello2Battery = tello2.GetBatteryState(50);
    std::cout << "tello 1 battery:" << tello1Battery << std::endl;
    std::cout << "tello 2 battery:" << tello2Battery << std::endl;
    if(tello1Battery < 30 || tello2Battery < 30){
        std::cout << "can't takeoff, battery too low" << std::endl;
    }

    tello1.SendCommand("takeoff");
    tello2.SendCommand("takeoff");
    while(!tello1.ReceiveResponse() || !tello2.ReceiveResponse()){
        sleep(1);
    }

    tello1.SendCommand("left 60");
    tello2.SendCommand("left 60");
    while(!tello1.ReceiveResponse() || !tello2.ReceiveResponse()){
        sleep(1);
    }

    tello1.SendCommand("forward 120");
    tello2.SendCommand("forward 120");
    while(!tello1.ReceiveResponse() || !tello2.ReceiveResponse()){
        sleep(1);
    }


    tello1.SendCommand("cw 90");
    tello2.SendCommand("cw 90");
    while(!tello1.ReceiveResponse() || !tello2.ReceiveResponse()){
        sleep(1);
    }

    tello1.SendCommand("forward 120");
    tello2.SendCommand("forward 120");
    while(!tello1.ReceiveResponse() || !tello2.ReceiveResponse()){
        sleep(1);
    }


    tello1.SendCommand("cw 90");
    tello2.SendCommand("cw 90");
    while(!tello1.ReceiveResponse() || !tello2.ReceiveResponse()){
        sleep(1);
    }

    tello1.SendCommand("forward 120");
    tello2.SendCommand("forward 120");
    while(!tello1.ReceiveResponse() || !tello2.ReceiveResponse()){
        sleep(1);
    }

    tello1.SendCommand("cw 90");
    tello2.SendCommand("cw 90");
    while(!tello1.ReceiveResponse() || !tello2.ReceiveResponse()){
        sleep(1);
    }

    tello1.SendCommand("forward 60");
    tello2.SendCommand("forward 60");
    while(!tello1.ReceiveResponse() || !tello2.ReceiveResponse()){
        sleep(1);
    }

    tello1.SendCommand("land");
    tello2.SendCommand("land");
    while(!tello1.ReceiveResponse() || !tello2.ReceiveResponse()){
        sleep(1);
    }
}
