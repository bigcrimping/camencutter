# camencutter

![photo](https://github.com/bigcrimping/camencutter/assets/74270551/11f13a29-afdc-4143-bf06-9556a08ede0e)

The camencutter project's aim is to accurately cut a camembert into three equal pieces.It is part of a wider series of projects on making smaller portion camembert bakers.

The machine uses a linear sliding table driven by a Nema11 stepper motor for the z translation of the “knife” element and a Nema17 to drive the platter which spins the cheese in rotation.

The control is basic, the microprocessor drives the knife and platter into the home position on start up using limit switches.

The construction is all 3D printed and the cheese holding element is cast in food safe silicone from a 3D printed mould. The knife element is 0.8mm stainless steel.

![camencutter](https://github.com/bigcrimping/camencutter/assets/74270551/246dbe5c-363b-4578-8a70-17a5648b6f20)


## Project Code

The code is here: https://github.com/bigcrimping/camencutter/tree/main/arduino/camencutter_V1

## Wiring

The wiring should be straightforward to implement using two stepper drivers

| Signal	| Pin Number |	Description |
| -------------- | ---------- | -------------------------------------------------------------- |
| platter_dirPin	| 2 |	Direction of the platter, connect to stepper driver for platter |
| platter_stepPin	| 3	| Step input of the platter, connect to stepper driver for platter |
| column_dirPin |	4	| Direction of the column, connect to column drive for platter |
| column_stepPin |	5 |	Step input of the column, connect to stepper driver for column |
| column_in |	6	| Home signal for the column, connect to limit switch |
| platter_in	| 7	| Home signal for the platter, connect to limit switch |
| button_in	| 13	| Button input to start the cutting routine |


## Mechanical Files

![render](https://github.com/bigcrimping/camencutter/assets/74270551/d099e0a7-cb91-4ba2-a950-62e0010efd23)

The parts are assembled with M3 cap head bolts

The mould is very basic 

![mould](https://github.com/bigcrimping/camencutter/assets/74270551/f7423079-69f6-42f8-a952-c750c1f0bfe7)


3MF files for the mould are here: https://github.com/bigcrimping/camencutter/tree/main/mechanics/cutter

3MF files for the mould are here: https://github.com/bigcrimping/camencutter/tree/main/mechanics/platter_mould
