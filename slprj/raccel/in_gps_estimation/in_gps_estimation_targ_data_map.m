    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 54;
            section.data(54)  = dumData; %prealloc

                    ;% rtP.Difference_ICPrevInput
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.TransferFcn_A
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.TransferFcn_C
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.SFunction5_P1_Size
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.SFunction5_P1
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% rtP.SFunction5_P2_Size
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% rtP.SFunction5_P2
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 8;

                    ;% rtP.SFunction5_P3_Size
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 9;

                    ;% rtP.SFunction5_P4_Size
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 11;

                    ;% rtP.SFunction5_P4
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 13;

                    ;% rtP.Gain8_Gain
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 14;

                    ;% rtP.Gain7_Gain
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 15;

                    ;% rtP.Gain_Gain
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 16;

                    ;% rtP.SFunction_P1_Size
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 17;

                    ;% rtP.SFunction_P1
                    section.data(15).logicalSrcIdx = 15;
                    section.data(15).dtTransOffset = 19;

                    ;% rtP.SFunction_P2_Size
                    section.data(16).logicalSrcIdx = 16;
                    section.data(16).dtTransOffset = 20;

                    ;% rtP.SFunction_P2
                    section.data(17).logicalSrcIdx = 17;
                    section.data(17).dtTransOffset = 22;

                    ;% rtP.SFunction_P3_Size
                    section.data(18).logicalSrcIdx = 18;
                    section.data(18).dtTransOffset = 23;

                    ;% rtP.SFunction_P4_Size
                    section.data(19).logicalSrcIdx = 20;
                    section.data(19).dtTransOffset = 25;

                    ;% rtP.SFunction_P4
                    section.data(20).logicalSrcIdx = 21;
                    section.data(20).dtTransOffset = 27;

                    ;% rtP.Gain2_Gain
                    section.data(21).logicalSrcIdx = 22;
                    section.data(21).dtTransOffset = 28;

                    ;% rtP.Gain3_Gain
                    section.data(22).logicalSrcIdx = 23;
                    section.data(22).dtTransOffset = 29;

                    ;% rtP.SFunction16_P1_Size
                    section.data(23).logicalSrcIdx = 24;
                    section.data(23).dtTransOffset = 30;

                    ;% rtP.SFunction16_P1
                    section.data(24).logicalSrcIdx = 25;
                    section.data(24).dtTransOffset = 32;

                    ;% rtP.SFunction16_P2_Size
                    section.data(25).logicalSrcIdx = 26;
                    section.data(25).dtTransOffset = 33;

                    ;% rtP.SFunction16_P2
                    section.data(26).logicalSrcIdx = 27;
                    section.data(26).dtTransOffset = 35;

                    ;% rtP.SFunction16_P3_Size
                    section.data(27).logicalSrcIdx = 28;
                    section.data(27).dtTransOffset = 36;

                    ;% rtP.SFunction16_P4_Size
                    section.data(28).logicalSrcIdx = 30;
                    section.data(28).dtTransOffset = 38;

                    ;% rtP.SFunction16_P4
                    section.data(29).logicalSrcIdx = 31;
                    section.data(29).dtTransOffset = 40;

                    ;% rtP.Step_Time
                    section.data(30).logicalSrcIdx = 32;
                    section.data(30).dtTransOffset = 41;

                    ;% rtP.Step_Y0
                    section.data(31).logicalSrcIdx = 33;
                    section.data(31).dtTransOffset = 42;

                    ;% rtP.Step_YFinal
                    section.data(32).logicalSrcIdx = 34;
                    section.data(32).dtTransOffset = 43;

                    ;% rtP.SineWave_Amp
                    section.data(33).logicalSrcIdx = 35;
                    section.data(33).dtTransOffset = 44;

                    ;% rtP.SineWave_Bias
                    section.data(34).logicalSrcIdx = 36;
                    section.data(34).dtTransOffset = 45;

                    ;% rtP.SineWave_Freq
                    section.data(35).logicalSrcIdx = 37;
                    section.data(35).dtTransOffset = 46;

                    ;% rtP.SineWave_Phase
                    section.data(36).logicalSrcIdx = 38;
                    section.data(36).dtTransOffset = 47;

                    ;% rtP.Gain1_Gain
                    section.data(37).logicalSrcIdx = 39;
                    section.data(37).dtTransOffset = 48;

                    ;% rtP.SFunction3_P1_Size
                    section.data(38).logicalSrcIdx = 40;
                    section.data(38).dtTransOffset = 49;

                    ;% rtP.SFunction3_P1
                    section.data(39).logicalSrcIdx = 41;
                    section.data(39).dtTransOffset = 51;

                    ;% rtP.SFunction3_P2_Size
                    section.data(40).logicalSrcIdx = 42;
                    section.data(40).dtTransOffset = 52;

                    ;% rtP.SFunction3_P2
                    section.data(41).logicalSrcIdx = 43;
                    section.data(41).dtTransOffset = 54;

                    ;% rtP.SFunction3_P3_Size
                    section.data(42).logicalSrcIdx = 44;
                    section.data(42).dtTransOffset = 55;

                    ;% rtP.SFunction3_P3
                    section.data(43).logicalSrcIdx = 45;
                    section.data(43).dtTransOffset = 57;

                    ;% rtP.SFunction3_P4_Size
                    section.data(44).logicalSrcIdx = 46;
                    section.data(44).dtTransOffset = 61;

                    ;% rtP.SFunction3_P4
                    section.data(45).logicalSrcIdx = 47;
                    section.data(45).dtTransOffset = 63;

                    ;% rtP.SFunction2_P1_Size
                    section.data(46).logicalSrcIdx = 48;
                    section.data(46).dtTransOffset = 64;

                    ;% rtP.SFunction2_P1
                    section.data(47).logicalSrcIdx = 49;
                    section.data(47).dtTransOffset = 66;

                    ;% rtP.SFunction2_P2_Size
                    section.data(48).logicalSrcIdx = 50;
                    section.data(48).dtTransOffset = 67;

                    ;% rtP.SFunction2_P2
                    section.data(49).logicalSrcIdx = 51;
                    section.data(49).dtTransOffset = 69;

                    ;% rtP.SFunction2_P3_Size
                    section.data(50).logicalSrcIdx = 52;
                    section.data(50).dtTransOffset = 70;

                    ;% rtP.SFunction2_P4_Size
                    section.data(51).logicalSrcIdx = 54;
                    section.data(51).dtTransOffset = 72;

                    ;% rtP.SFunction2_P4
                    section.data(52).logicalSrcIdx = 55;
                    section.data(52).dtTransOffset = 74;

                    ;% rtP.Constant2_Value
                    section.data(53).logicalSrcIdx = 56;
                    section.data(53).dtTransOffset = 75;

                    ;% rtP.Constant3_Value
                    section.data(54).logicalSrcIdx = 57;
                    section.data(54).dtTransOffset = 76;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.ManualSwitch_CurrentSetting
                    section.data(1).logicalSrcIdx = 58;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% rtB.gho24r3wjp
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.imhbzzo51g
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.mqkohde3av
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.k3khppcoob
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.ixicelz4a0
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.orzekcshh1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.f0b2eyvx0s
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.apwxdnsmjg
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.jvz2qkejcz
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.n4bmglhsm1
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.fa5bpj2f2b
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.jdacxbno0x
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hs5sslgrvi
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% rtDW.cywm4bsd5e.LoggedData
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.aglikhlqco.LoggedData
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.odrrudiher.LoggedData
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.gsjw3qyczu.LoggedData
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.fg3eckn3eu.LoggedData
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.k32v50utzr.LoggedData
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.bmvwp1nucp.LoggedData
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.kh0put4mx0.LoggedData
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.o4iq1brz0d.LoggedData
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% rtDW.dqsf2qhlqe
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.pi102jxxgd
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 3;

                    ;% rtDW.gythey2jbv
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 6;

                    ;% rtDW.kj3fntqjhm
                    section.data(4).logicalSrcIdx = 13;
                    section.data(4).dtTransOffset = 9;

                    ;% rtDW.gw33k54ujt
                    section.data(5).logicalSrcIdx = 14;
                    section.data(5).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2226012495;
    targMap.checksum1 = 2004764594;
    targMap.checksum2 = 3757314384;
    targMap.checksum3 = 185473456;

