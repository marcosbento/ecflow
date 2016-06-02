(char*) " !=========================================================== ",
(char*) " ! Name : ",
(char*) " ! Author : ",
(char*) " ! Revision : $Revision: #17 $ ",
(char*) " ! ",
(char*) " ! Copyright 2009-2016 ECMWF. ",
(char*) " ! This software is licensed under the terms of the Apache Licence version 2.0 ",
(char*) " ! which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. ",
(char*) " ! In applying this licence, ECMWF does not waive the privileges and immunities ",
(char*) " ! granted to it by virtue of its status as an intergovernmental organisation ",
(char*) " ! nor does it submit to any jurisdiction. ",
(char*) " ! ",
(char*) " ! Description : ",
(char*) " ! this file may be found in ",
(char*) " ! - sources in order to generate xcdp.menu.h ",
(char*) " ! - ~/.ecflowrc/xcdp.menu # edit backup remove (reset) ",
(char*) " ! - ~/ is preferred to $HOME ",
(char*) " ! - menus can call system command ",
(char*) " !=========================================================== ",
(char*) " ! ",
(char*) " ! Format ",
(char*) " !------- ",
(char*) " ! menu TITLE ",
(char*) " ! { ",
(char*) " ! (vis flg,enable flg,title,command,question,answer) ",
(char*) " ! } ",
(char*) " ! ",
(char*) " !=========================================================== ",
(char*) " ! ",
(char*) " ! Values for the status flags ",
(char*) " !---------------------------- ",
(char*) " ! ",
(char*) " !NONE ALL UNKNOWN SUSPENDED COMPLETE QUEUED SUBMITTED ACTIVE ",
(char*) " !ABORTED CLEAR SET SHUTDOWN HALTED ",
(char*) " ! ",
(char*) " ! Values for type flags ",
(char*) " !---------------------- ",
(char*) " ! ",
(char*) " !NONE ALL SERVER SUITE FAMILY TASK EVENT ",
(char*) " ! ",
(char*) " ! Values for visible flags ",
(char*) " !------------------------- ",
(char*) " ! ",
(char*) " !NONE ALL SERVER SUITE FAMILY TASK EVENT ",
(char*) " ! ",
(char*) " ! Values for special flags ",
(char*) " !------------------------- ",
(char*) " ! ",
(char*) " !NONE ALL HAS_TRIGGERS HAS_TIME HAS_DATE ",
(char*) " ! ",
(char*) " !=========================================================== ",
(char*) "  ",
(char*) " !============================================================================== ",
(char*) " ! Main menu ",
(char*) " !============================================================================== ",
(char*) "  ",
(char*) " version 1 0 0 ; ",
(char*) "  ",
(char*) " menu 'MAIN' ",
(char*) " { ",
(char*) " (~SUSPENDED & NODE, ALL, 'Suspend', 'suspend <full_name>') ",
(char*) " (SUSPENDED & NODE, ALL, 'Resume', 'resume <full_name>') ",
(char*) "  ",
(char*) " ( TASK, ~ACTIVE & ~SUBMITTED, 'Rerun', 'force queued <full_name>') ",
(char*) " ( FAMILY, ~ACTIVE & ~SUBMITTED, 'Rerun', 'run <full_name>') ",
(char*) "  ",
(char*) " (TASK|ALIAS, SUBMITTED|ACTIVE, 'Set complete', ",
(char*) " 'force complete <full_name>', ",
(char*) " 'Have you checked that the job is not active anymore (jobstatus) ?', YES) ",
(char*) " (TASK|ALIAS, UNKNOWN|QUEUED|ABORTED, 'Set complete', ",
(char*) " 'force complete <full_name>') ",
(char*) " (TASK|ALIAS, SUBMITTED|ACTIVE, 'Set aborted', ",
(char*) " 'force aborted <full_name>', ",
(char*) " 'Have you checked that the job is not active anymore (jobstatus) ?', YES) ",
(char*) " (TASK|ALIAS, UNKNOWN|QUEUED|COMPLETE, 'Set aborted', ",
(char*) " 'force aborted <full_name>') ",
(char*) "  ",
(char*) " (TASK|ALIAS, ~ACTIVE & ~SUBMITTED, 'Execute', 'run <full_name>') ",
(char*) "  ",
(char*) " (SUITE|TASK|FAMILY, ~ACTIVE & ~SUBMITTED, 'Requeue', ",
(char*) " 'requeue -f <full_name>', ",
(char*) " 'Confirm requeuing of <full_name>', YES) ",
(char*) "  ",
(char*) " (SUITE|FAMILY, ABORTED | SUSPENDED, 'Requeue aborted', ",
(char*) " 'requeue -a <full_name>', ",
(char*) " 'Confirm requeuing of aborted tasks from <full_name>', YES) ",
(char*) "  ",
(char*) " (ALL,ALL,'-',SEPARATOR) ",
(char*) "  ",
(char*) " (SUITE|TASK|FAMILY,(QUEUED) & (HAS_TRIGGERS|HAS_TIME|HAS_DATE),'Delete',MENU) ",
(char*) " (NODE|ALIAS,ALL,'Special', MENU) ",
(char*) " (NODE& ADMIN, ALL,'Force', MENU) ",
(char*) " ((NODE|ALIAS)& ADMIN, ALL,'Order', MENU) ",
(char*) "  ",
(char*) " (ALL,ALL,'-',SEPARATOR ,'',YES) ",
(char*) " (SUITE|FAMILY|TASK, ALL, 'Web...', 'url <full_name> ', '', YES) ",
(char*) "  ",
(char*) " (ALL,ALL,'-',SEPARATOR) ",
(char*) "  ",
(char*) " (SUITE & (OPER|ADMIN) ,UNKNOWN|COMPLETE,'Begin', ",
(char*) " 'begin <full_name>','',YES) ",
(char*) "  ",
(char*) " (SUITE & (OPER|ADMIN) ,~SUBMITTED & ~ACTIVE,'Cancel', ",
(char*) " 'cancel -y <full_name>', ",
(char*) " 'Do you really want to cancel suite <full_name> ?',NO) ",
(char*) "  ",
(char*) " ! Events ",
(char*) " !--------------------------------- ",
(char*) "  ",
(char*) " (EVENT, CLEAR, 'Set' , 'force set <full_name>', '',YES) ",
(char*) " (EVENT, SET, 'Clear', 'force clear <full_name>', '',YES) ",
(char*) "  ",
(char*) " !!----------------------------------- ",
(char*) "  ",
(char*) " (SERVER & (ADMIN|OPER) & LOCKED , ALL , 'Unlock', 'unlock -y', ",
(char*) " 'Before going further, please check why the server was locked.',NO) ",
(char*) " (ALL,ALL,'-',SEPARATOR,'',YES) ",
(char*) "  ",
(char*) " !!----------------------------------- ",
(char*) "  ",
(char*) " (SERVER,SHUTDOWN|HALTED, 'Restart', ",
(char*) " 'restart -y','Restart the server in <node_name>?' ,NO) ",
(char*) " (SERVER,~SHUTDOWN, 'Shutdown', ",
(char*) " 'shutdown -y','Shutdown the server in <node_name>?',NO) ",
(char*) " (SERVER,~HALTED, 'Halt', ",
(char*) " 'halt -y','Halt the server in <node_name>?',NO) ",
(char*) " (SERVER,HALTED, 'Terminate', ",
(char*) " 'terminate -y','Terminate the server in <node_name>?',NO) ",
(char*) " (ALL,ALL,'-',SEPARATOR,'',YES) ",
(char*) " (SERVER,ALL, 'Checkpoint','check','',YES) ",
(char*) " (SERVER,HALTED, 'Recover', ",
(char*) " 'recover -y','Recover the server in <node_name>?',NO) ",
(char*) "  ",
(char*) " !!----------------------------------- ",
(char*) "  ",
(char*) " (LIMIT , ALL, 'Reset' , ",
(char*) " 'reset <full_name>', 'Confirm resetting <full_name>', YES) ",
(char*) " (ALIAS , ALL, 'Remove', ",
(char*) " 'cancel -y <full_name>', 'Confirm remove alias <full_name>', YES) ",
(char*) "  ",
(char*) " !!----------------------------------- ",
(char*) "  ",
(char*) " (ALL,ALL,'-',SEPARATOR) ",
(char*) "  ",
(char*) " (TASK|LIMIT|LABEL|METER|REPEAT|VARIABLE, ALL , 'Edit...', WINDOW(Edit)) ",
(char*) " (TASK|ALIAS, ALL , 'Output...', WINDOW(Output) ) ",
(char*) "  ",
(char*) " (TASK|ALIAS, SUBMITTED|ACTIVE , 'Status...', WINDOW(Jobstatus)) ",
(char*) " (ALIAS, ALL , 'Job...', WINDOW(Job) ) ",
(char*) " (TASK|ALIAS, ALL , 'Script...', WINDOW(Script) ) ",
(char*) "  ",
(char*) " (SERVER, ALL , 'Suites...', WINDOW(Suites) ) ",
(char*) " (SERVER, ALL , 'History...', WINDOW(History) ) ",
(char*) " (SERVER, ALL , 'Zombies...', WINDOW(Zombies) ) ",
(char*) " (ALL,ALL,'-',SEPARATOR) ",
(char*) " (SERVER, ALL , 'Options...', WINDOW(Options) ) ",
(char*) " } ",
(char*) "  ",
(char*) " !============================================================================== ",
(char*) " ! Status submenu ",
(char*) " !============================================================================== ",
(char*) "  ",
(char*) " menu 'Status' ",
(char*) " { ",
(char*) " (SUITE|TASK|FAMILY, ~SUSPENDED,'Suspend', 'suspend <full_name>', '',YES) ",
(char*) " (SUITE|TASK|FAMILY, SUSPENDED ,'Resume', 'resume <full_name>', '',YES) ",
(char*) "  ",
(char*) " (ALL,ALL,'-',SEPARATOR) ",
(char*) "  ",
(char*) " (TASK, ~ACTIVE & ~SUBMITTED, 'Rerun', 'force queued <full_name>', '',YES) ",
(char*) " (TASK, ~COMPLETE, 'Set complete', 'force complete <full_name>', '',YES) ",
(char*) "  ",
(char*) " (SUITE|TASK|FAMILY|ALIAS, ~ACTIVE & ~SUBMITTED, ",
(char*) " 'Requeue','requeue -f <full_name>', 'Confirm requeuing of <full_name>', YES) ",
(char*) "  ",
(char*) " (SUITE|FAMILY, ABORTED | SUSPENDED, ",
(char*) " 'Requeue aborted','requeue -a <full_name>', ",
(char*) " 'Confirm requeuing aborted tasks below <full_name>', YES) ",
(char*) " } ",
(char*) "  ",
(char*) " !============================================================================== ",
(char*) " ! Suite submenu ",
(char*) " !============================================================================== ",
(char*) "  ",
(char*) " menu 'Suite' ",
(char*) " { ",
(char*) " (SUITE,UNKNOWN|COMPLETE,'Begin','begin <full_name>','',YES) ",
(char*) "  ",
(char*) " (SUITE,ALL,'Cancel','cancel -y <full_name>', ",
(char*) " 'Do you really want to cancel <full_name> ?',NO) ",
(char*) "  ",
(char*) " (ALL,ALL,'-',SEPARATOR) ",
(char*) " } ",
(char*) "  ",
(char*) " !============================================================================== ",
(char*) " ! Delete submenu ",
(char*) " !============================================================================== ",
(char*) "  ",
(char*) " menu 'Delete' ",
(char*) " { ",
(char*) " (ALL,HAS_TRIGGERS|HAS_TIME|HAS_DATE, 'All dependencies', ",
(char*) " 'delete -tdT <full_name>') ",
(char*) " (ALL,HAS_TRIGGERS, 'Trigger dependencies','delete -T <full_name>') ",
(char*) " (ALL,HAS_TIME, 'Time dependencies','delete -t <full_name>') ",
(char*) " (ALL,QUEUED, 'Date dependencies','delete -d <full_name>') ",
(char*) " } ",
(char*) "  ",
(char*) " menu \"Order\" ",
(char*) " { ",
(char*) " (ALL,ALL,'Top','order -t top <full_name>') ",
(char*) " (ALL,ALL,'Up','order -t up <full_name>') ",
(char*) " (ALL,ALL,'Down','order -t down <full_name>') ",
(char*) " (ALL,ALL,'Bottom','order -t bottom <full_name>') ",
(char*) " (ALL,ALL,'Alphabetically','order -t alphabetical <full_name>') ",
(char*) " } ",
(char*) "  ",
(char*) " menu \"Force\" ",
(char*) " { ",
(char*) " (NODE, ~UNKNOWN, 'Unknown', 'force -q -r unknown <full_name>') ",
(char*) " (NODE, ~COMPLETE & ~ACTIVE & ~SUBMITTED, 'Complete', ",
(char*) " 'force =q -r complete <full_name>', ",
(char*) " 'Check running/queued jobs and Confirm force complete of <full_name>', YES) ",
(char*) " (NODE, ~QUEUED & ~ACTIVE & ~SUBMITTED, 'Queued', ",
(char*) " 'force -q -r queued <full_name>') ",
(char*) " (NODE, ~SUBMITTED & ~ACTIVE,'Submitted', ",
(char*) " 'force -q -r submitted <full_name>') ",
(char*) " (NODE, ~ACTIVE, 'Active', 'force -q -r active <full_name>') ",
(char*) " (NODE, ~ABORTED, 'Aborted', 'force -q -r aborted <full_name>', ",
(char*) " 'Check running/queued jobs and Confirm force submitted of <full_name>', YES) ",
(char*) " } ",
(char*) "  ",
(char*) " menu \"Special\" ",
(char*) " { ",
(char*) " (SUITE|FAMILY,(ACTIVE|SUBMITTED|ABORTED),'Kill', ",
(char*) " 'kill <full_name>','',YES) ",
(char*) " (TASK|ALIAS,(ACTIVE|SUBMITTED),'Kill','kill <full_name>','',YES) ",
(char*) "  ",
(char*) " (ALL,ALL,'Check',WINDOW(Check),'',YES) ",
(char*) " (TASK|ALIAS,ALL,'Free password','alter -v <full_name> SMSPASS FREE') ",
(char*) " (TASK|ALIAS,ALL,'ClearZ','alter -F zombie <full_name>') ",
(char*) " ((SUITE|FAMILY), SELECTION, 'Plug into selected node', PLUG) ",
(char*) " (SUITE|SERVER, ALL, 'Collect...', WINDOW(Collector)) ",
(char*) " (SERVER|SUITE,ALL,'Windows', MENU) ",
(char*) " (ALL,ALL,'echo', 'sh echo ok') ",
(char*) " } ",
(char*) "  ",
(char*) " menu \"Windows\" ",
(char*) " { ",
(char*) " (SERVER, ALL , 'Info...', WINDOW(Info)) ",
(char*) " (SERVER, ALL , 'Man...', WINDOW(Manual)) ",
(char*) " (SERVER, ALL , 'Var...', WINDOW(Variables)) ",
(char*) " (SERVER, ALL , 'Msg...', WINDOW(Messages)) ",
(char*) " (SERVER, ALL , 'Why...', WINDOW(Why)) ",
(char*) " (SERVER, ALL , 'Triggers...', WINDOW(Triggers)) ",
(char*) " (SERVER, ALL , 'Check...', WINDOW(Check)) ",
(char*) " (SERVER, ALL , 'Jobstatus...', WINDOW(Jobstatus)) ",
(char*) " } ",
NULL
