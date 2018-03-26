// The file creates links to external webpages.
// External means - urls to ARM, Keil, and CMSIS pages
//                - other external pages have not been added so far.

// constuctor for the array of objects
function urlKey(key, url, txt)  {
  try{
	this.key = key;                     // key - links the url to code
	this.url = url;                     // web link 
	this.txt = txt;                     // Text shown for the link
	this.ext  = '<a class="el" href="' + this.url + '" target="_blank">' + this.txt + '</a>';  // for \urlout{1 parameter}
	this.ext2 = '<a class="el" href="' + this.url + '" target="_blank">';                      // for urlout{2 parameter}
	this.loc  = '<a class="el" href="' + this.url + '">' + this.txt + '</a>';                  // for \url{1 parameter}
	this.loc2 = '<a class="el" href="' + this.url + '">';                                      // for \url{2 parameter}
  }
  catch(err) {
    alert(err.message);
  }
};

// array of objects
var arrurl = [];

// fill array with
//                         Key                      url; relative liks are possible                                                displayed Text           
//                         for uv4 docs - page name
//                         for rest - create new key 

 arrurl.push( new urlKey( "keilweb",                "http://www.keil.com",                                                      "Keil webpage")       );
 arrurl.push( new urlKey( "keilboards",             "http://www.keil.com/boards2",                                              "Board List for ARM Cortex-M") );
 arrurl.push( new urlKey( "ARM-SW-Pack",            "http://www.keil.com/dd2/pack/",                                            "ARM:CMSIS Software Pack") );
 arrurl.push( new urlKey( "SW-Pack",                "http://www.keil.com/dd2/pack/",                                            "Software Pack") );
 arrurl.push( new urlKey( "MDK-Core",               "http://www2.keil.com/mdk5/core/",                                          "MDK Core") );

 arrurl.push( new urlKey( "CMSIS-Driver",           "http://www.keil.com/cmsis/driver",                                         "CMSIS-Driver")     );
 arrurl.push( new urlKey( "CMSIS-Driver-Ref",       "http://www.keil.com/pack/doc/CMSIS/Driver/html/modules.html",              "CMSIS-Driver Reference"));
 arrurl.push( new urlKey( "CMSIS-RTOS1",            "http://www.keil.com/pack/doc/CMSIS/RTOS/html/index.html",                  "CMSIS-RTOS v1")     );
 arrurl.push( new urlKey( "CMSIS-RTOS1-Ref",        "http://www.keil.com/pack/doc/CMSIS/RTOS/html/modules.html",                "CMSIS-RTOS Reference"));
 arrurl.push( new urlKey( "CMSIS-RTOS2",            "http://www.keil.com/pack/doc/CMSIS/RTOS2/html/index.html",                 "CMSIS-RTOS v2")     );
 arrurl.push( new urlKey( "CMSIS-RTOS2-Ref",        "http://www.keil.com/pack/doc/CMSIS/RTOS2/html/modules.html",               "CMSIS-RTOS Refernece")     );
 arrurl.push( new urlKey( "CMSIS-RTX4",             "http://www.keil.com/pack/doc/CMSIS/RTOS/html/rtxImplementation.html",      "CMSIS-RTOS RTX v4")     );
 arrurl.push( new urlKey( "CMSIS-RTX5",             "http://www.keil.com/pack/doc/CMSIS/RTOS2/html/rtx5_impl.html",             "CMSIS-RTOS RTX v5")     );
 arrurl.push( new urlKey( "RTX-Conf-CM4",           "http://www.keil.com/pack/doc/CMSIS/RTOS/html/configure.html",                 "RTX_Conf_CM.c")      );
 arrurl.push( new urlKey( "RTX-Conf-CM5",           "http://www.keil.com/pack/doc/CMSIS/RTOS2/html/config_rtx5.html",              "RTX_Conf_CM.c")      );

 arrurl.push( new urlKey( "Flash-API",              "http://www.keil.com/pack/doc/CMSIS/Driver/html/group__flash__interface__gr.html",  "Flash (API)"));
 arrurl.push( new urlKey( "SPI-API",                "http://www.keil.com/pack/doc/CMSIS/Driver/html/group__spi__interface__gr.html",    "SPI (API)"));
 arrurl.push( new urlKey( "MCI-API",                "http://www.keil.com/pack/doc/CMSIS/Driver/html/group__mci__interface__gr.html",    "MCI (API)"));
 arrurl.push( new urlKey( "USB-API",                "http://www.keil.com/pack/doc/CMSIS/Driver/html/group__usb__interface__gr.html",    "USB (API)"));
 arrurl.push( new urlKey( "NAND-API",               "http://www.keil.com/pack/doc/CMSIS/Driver/html/group__nand__interface__gr.html",   "NAND (API)"));
 arrurl.push( new urlKey( "ARM-MCI-Capabilities",   "http://www.keil.com/pack/doc/CMSIS/Driver/html/group__mci__interface__gr.html#structARM__MCI__CAPABILITIES",  "MCI driver capabilities"));

 arrurl.push( new urlKey( "mbedTLS",                "http://www.keil.com/pack/doc/mbedTLS/html/index.html",                        "mbed TLS")           );

 arrurl.push( new urlKey( "uv4_ca_packinstaller",   "http://www.keil.com/support/man/docs/uv4/uv4_ca_packinstaller.htm",           "Pack Installer")     );
 arrurl.push( new urlKey( "uv4_db_dbg_serialwin",   "http://www.keil.com/support/man/docs/uv4/uv4_db_dbg_serialwin.htm",           "Debug (printf) Viewer"));
 arrurl.push( new urlKey( "uv4_ut_fcarmuv",         "http://www.keil.com/support/man/docs/uv4/uv4_ut_fcarmuv.htm",                 "FCARM"));
// fix these two below
 arrurl.push( new urlKey( "uv4_user_code_template", "http://www.keil.com/support/man/docs/uv4/uv4_ca_sourcefiles.htm",             "User code template") );
 arrurl.push( new urlKey( "uv4_ca_sourcefiles",     "http://www.keil.com/support/man/docs/uv4/uv4_ca_sourcefiles.htm",             "User code template") );
 arrurl.push( new urlKey( "uv4_ca_updswcmpfiles",   "http://www.keil.com/support/man/docs/uv4/uv4_ca_updswcmpfiles.htm",           "Update Software Component Files"));
 arrurl.push( new urlKey( "uv4_dg_mergetoolmnu",    "http://www.keil.com/support/man/docs/uv4/uv4_dg_mergetoolmnu.htm",            "Configure Merge Tool"));

 arrurl.push( new urlKey( "uv4-Event-Recorder",   "http://www.keil.com/support/man/docs/uv4/uv4_db_dbg_evr.htm", "Event Recorder Window"));
 arrurl.push( new urlKey( "uv4-Component-Viewer", "http://www.keil.com/support/man/docs/uv4/uv4_db_dbg_scvd_viewer.htm", "Component Viewer"));
 
 arrurl.push( new urlKey( "gs_low_level_routine",   "http://www.keil.com/support/man/docs/gsac/gsac_lowlevelroutinescortex.htm",   "Low level routine")  );
 arrurl.push( new urlKey( "startup_device",         "http://www.keil.com/support/man/docs/gsac/gsac_startupcodecortex.htm",        "startup_device.s")   );

 arrurl.push( new urlKey( "MDK-Pro-Editions",       "http://www2.keil.com/mdk5/editions/pro",                                      "MDK-Professional")   );
 arrurl.push( new urlKey( "MDK-Plus-Editions",      "http://www2.keil.com/mdk5/editions/plus",                                     "MDK-Plus")           );

 arrurl.push( new urlKey( "Event-Recorder",         "http://www.keil.com/pack/doc/compiler/EventRecorder/html/index.html",         "Event Recorder")     );         
 arrurl.push( new urlKey( "Event-Recorder-About",   "http://www.keil.com/pack/doc/compiler/EventRecorder/html/er_overview.html#AboutEventRecorder","Event Recorder")     );  
 arrurl.push( new urlKey( "Event-Recorder-Enable",  "http://www.keil.com/pack/doc/compiler/EventRecorder/html/er_use.html#Add_Event_Recorder",     "Add Event Recorder"));
 arrurl.push( new urlKey( "Event-Recorder-Initialize",   "http://www.keil.com/pack/doc/compiler/EventRecorder/html/group__EventRecorder__Setup.html",   "Add Initialization Code"));
 arrurl.push( new urlKey( "Event-Recorder-Configure",   "http://www.keil.com/pack/doc/compiler/EventRecorder/html/er_overview.html#er_config",   "Configure Event Recorder"));
 arrurl.push( new urlKey( "Debug-Variant-Select",   "http://www.keil.com/pack/doc/compiler/EventRecorder/html/er_use.html#Debug_Variants", "Select Debug Variant"));
 
 
 arrurl.push( new urlKey( "Component-Viewer-About",       "http://www.keil.com/pack/doc/compiler/EventRecorder/html/er_overview.html#AboutComponentViewer", "Component Viewer"));

 arrurl.push( new urlKey( "USB-Resource-Req",        "../../USB/html/usb_resource_requirements.html",                     "USB Resource Requirements"));
 arrurl.push( new urlKey( "USBD-MSC-Ex",             "../../USB/html/dev_msc_tutorial.html",                              "USB Device Mass Storage Example"));
 arrurl.push( new urlKey( "USBH-MSC-Ex",             "../../USB/html/host_msc_tutorial.html",                             "USB Host Mass Storage Example"));
 arrurl.push( new urlKey( "FTP-Server-Ex",           "../../Network/html/_f_t_p__server__example.html",                   "FTP Server Example"));
 arrurl.push( new urlKey( "GEN-MDK-Pro",             "../../General/html/index.html",                                     "MDK-Professional Middleware"));
 arrurl.push( new urlKey( "MW-General",              "../../General/html/index.html",                                     "MDK-Middleware"));
 arrurl.push( new urlKey( "MW-FileSystem",           "../../FileSystem/html/index.html",                                  "File System Component"));
 arrurl.push( new urlKey( "MW-Graphic",              "../../Graphic/html/index.html",                                     "Graphics Component"));
 arrurl.push( new urlKey( "MW-Network",              "../../Network/html/index.html",                                     "Network Component"));
 arrurl.push( new urlKey( "MW-USB",                  "../../USB/html/index.html",                                         "USB Component"));
 arrurl.push( new urlKey( "MW-Board",                "../../Board/html/index.html",                                       "Board Support Component"));

 arrurl.push( new urlKey( "STM32Cube",               "http://www.keil.com/pack/doc/STM32Cube/General/html/index.html",    "STMicroelectronic's STM32Cube"));
 arrurl.push( new urlKey( "DAVE",                    "http://www.keil.com/appnotes/docs/apnt_258.asp",                    "Infineon's DAVE"));


// helper variable
var arr_length = arrurl.length;


// this function is called from doxygen with the command \url{key}
// where key - is the Key in the array arrurl
// the function opens the link in current browser window
function link_loc(key)  {
  for ( var i=0; i < arr_length; i++ ) {
    if (arrurl[i].key == key)  {              // find link in array
       document.write(arrurl[i].loc);         // show default text and open link in browser
       return;
    }
  }
  key_is_missing(key);
}; 

// called with \url{key, your text}
function link_loc2(key, txt)  {
  for ( var i=0; i < arr_length; i++ ) {
    if (arrurl[i].key == key)  {                              // find link in array
       document.write(arrurl[i].loc2 + txt + '</a>');         // show your text and open link in new browser
       return;
    }
  }
  key_is_missing(key);
}; 

// this function is called from doxygen with the command \urlout{key}
// where key - is the Key in the array arrurl
// opens the link in a new browser window
function link_ext(key)  {
  for ( var i=0; i < arr_length; i++) {
    if (arrurl[i].key == key)  {              // find link in array
       document.write(arrurl[i].ext);         // show default text and open link in new browser window
       return;
    }
  }
  key_is_missing(key);
}; 

// called with \urlout{key, your text}
function link_ext2(key, txt)  {
  for ( var i=0; i < arr_length; i++ ) {
    if (arrurl[i].key == key)  {                        // find link in array
       document.write(arrurl[i].ext2 + txt + '</a>');   // show your text and open link in another browser window
       return;											
    }
  }
  key_is_missing(key);
}; 

// inform user about missing key
function key_is_missing(key) {
    alert('URL-key: "' + key + '" not found. \n - Verify your document or \n - add the key to "URL_keys.js"');
};



