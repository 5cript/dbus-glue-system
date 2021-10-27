#pragma once

#include <dbus-glue/dbus_interface.hpp>

namespace BlueZ::org::bluez::hci::dev
{
  class Device
	{
	public:
		virtual ~Device() = default;

	public: // Methods
		virtual auto Connect() -> void = 0;
		virtual auto CancelPairing() -> void = 0;
		virtual auto ConnectProfile(std::string const& uuid) -> void = 0;
		virtual auto Disconnect() -> void = 0;
		virtual auto DisconnectProfile(std::string const& uuid) ->	void = 0;
		virtual auto Pair() -> void = 0;

	public: // Properties
		DBusGlue::readable <std::vector <std::string>> UUIDs;
		DBusGlue::read_writeable <bool> Blocked;
		DBusGlue::readable <bool> Connected;
		DBusGlue::readable <bool> LegacyPairing;
		DBusGlue::readable <bool> Paired;
		DBusGlue::readable <bool> ServicesResolved;
		DBusGlue::read_writeable <bool> Trusted;
		DBusGlue::readable <std::unordered_map <std::string, DBusGlue::variant>> ServiceData;
		DBusGlue::readable <std::unordered_map <uint16_t, DBusGlue::variant>> ManufacturerData;
		DBusGlue::readable <int16_t> RSSI;
		DBusGlue::readable <int16_t> TxPower;
		DBusGlue::readable <DBusGlue::object_path> Adapter;
		DBusGlue::readable <std::string> Address;
		DBusGlue::readable <std::string> AddressType;
		DBusGlue::read_writeable <std::string> Alias;
		DBusGlue::readable <std::string> Icon;
		DBusGlue::readable <std::string> Modalias;
		DBusGlue::readable <std::string> Name;
		DBusGlue::readable <uint16_t> Appearance;
		DBusGlue::readable <uint32_t> Class;

	public: // Signals
	};
}

DBUS_DECLARE_NAMESPACE
(
    (BlueZ)(org)(bluez)(hci)(dev),
    Device,
    DBUS_DECLARE_METHODS(Connect, CancelPairing, ConnectProfile, Disconnect, DisconnectProfile, Pair),
    DBUS_DECLARE_PROPERTIES(
        UUIDs, Blocked, Connected, LegacyPairing, Paired, ServicesResolved, Trusted, ServiceData,
        ManufacturerData, RSSI, TxPower, Adapter, Address, AddressType, Alias, Icon, Modalias, Name, Appearance, Class
    ),
    DBUS_DECLARE_NO_SIGNALS
)
