#pragma once

#include <dbus-glue/dbus_interface.hpp>

namespace DBus::org::freedesktop::DBus
{
    class ObjectManager
	{
	public:
		virtual ~ObjectManager() = default;

	public: // Methods
		virtual auto GetManagedObjects() -> std::unordered_map <
		    DBusGlue::object_path,
		    std::unordered_map <
		        std::string,
		        std::unordered_map <std::string, DBusGlue::variant>
		    >
		> = 0;

	public: // Properties

	public: // Signals
		DBusGlue::signal <
		    void
		    (
		        DBusGlue::object_path,
		        std::unordered_map <std::string, std::unordered_map <std::string, DBusGlue::variant>>
		    )
		> InterfacesAdded;
		DBusGlue::signal <void(DBusGlue::object_path, std::vector <std::string>)> InterfacesRemoved;
	};

	class Introspectable
	{
	public:
		virtual ~Introspectable() = default;

	public: // Methods
		virtual auto Introspect() -> std::string /*xml*/ = 0;

	public: // Properties
	public: // signals
	};
}

DBUS_DECLARE_NAMESPACE
(
    (DBus)(org)(freedesktop)(DBus),
    Introspectable,
    DBUS_DECLARE_METHODS(Introspect),
    DBUS_DECLARE_NO_PROPERTIES,
    DBUS_DECLARE_NO_SIGNALS
)

DBUS_DECLARE_NAMESPACE
(
    (DBus)(org)(freedesktop)(DBus),
    ObjectManager,
    DBUS_DECLARE_METHODS(GetManagedObjects),
    DBUS_DECLARE_NO_PROPERTIES,
    DBUS_DECLARE_SIGNALS(InterfacesAdded, InterfacesRemoved)
)
