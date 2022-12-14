//==========================================================================================================
// pilot_adc.h - Defines the interface that reads the pilot-pin ADC and converts to voltages
//==========================================================================================================
#pragma once

class CPilotADC
{
public:

    // Constructor, initializes the file descriptors
    CPilotADC() {m_sd_neg = m_sd_pos = -1;}

    // Destructor() - Closes the devices
    ~CPilotADC() {close();}

    // Opens the device files.  Returns 'false' if it can't
    bool    init();

    // Closes the device files
    void    close();

    // Fetches the two voltages
    void    get_voltages(float *posv, float* negv);

    // Returns true if init() failed (or was never called)
    bool    is_init_failure() {return m_sd_pos == -1 || m_sd_neg == -1;}

protected:

    enum vchannel_t {POSV, NEGV};
    
    // Returns the raw voltage reading in millivolts
    int     read_raw_voltage(vchannel_t channel);

    // Returns an adjusted (for DC offset) voltage reading in millivolts
    int     read_adjusted_voltage(vchannel_t channel);

    // File descriptors for the devices that read the negative and positive voltages
    int     m_sd_neg, m_sd_pos;

    // The DC offset values (in millivolts) for each channel
    int     m_posv_dc_offset, m_negv_dc_offset;

};
