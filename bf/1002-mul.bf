 ++++[>++++[>+++<-]<-]   # writes 48 / 0x30 / '0' in cell(2)
    ,>,>                    reads two numbers in cell(0) and cell(1)
    [<-<->>-]               decrements cell(0) and cell(1) by 48 / 0x30 / '0'
    <<                      moves to cell(0)
    [                       mulitplies the loop
        >                   moves to cell(1)
        [>+>+<<-]           moves cell(1) to cell(2) and cell(3)
        >>                 # moves to cell(3)
        [<<+>>-]            moves cell(3) back to cell(1)
        <<<-               # decrements cell(0)
    ]
    >[-]<                  # sets cell(1) to 0 so that it can be used as counter (we are in cell 0 here)
    ++++[>++++[>+++<-]<-]   adds 48 / 0x30 / '0' to cell(2) cell 2 has the result
    >>.                     prints the result
