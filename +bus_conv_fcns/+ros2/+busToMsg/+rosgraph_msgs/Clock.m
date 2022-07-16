function rosmsgOut = Clock(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.clock = bus_conv_fcns.ros2.busToMsg.builtin_interfaces.Time(slBusIn.clock,rosmsgOut.clock(1));
end
