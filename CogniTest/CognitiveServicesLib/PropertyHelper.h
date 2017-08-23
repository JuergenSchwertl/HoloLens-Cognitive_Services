#pragma once

///<summary>defines an internal variable name for the json property name</summary>
#define __JSON_PROPERTYNAME( propname ) m_##propname##_JsonName

///<summary>defines an internal variable name for the property backing store</summary>
#define PROPERTY_VARIABLE( propname ) m_##propname

///<summary>returns the json property name of the given property name as <see cref="Platform::String" /> reference</summary>
#define JSON_PROPERTYNAME( propname ) ((Platform::String^) __JSON_PROPERTYNAME( propname ))

///<summary>returns the json property name of the given property name as <see cref="Platform::String" /> reference</summary>
#define JSON_PROPERTYNAME_PCWSTR( propname ) ((Platform::String^) __JSON_PROPERTYNAME( propname ))->Data()


///<summary>Defines a C# consumable property including it's backing store and a json name string</summary>
#define DEFINE_PROPERTY(propclass, proptype, propname, jsonname) \
	property proptype propname { proptype get(); void set(proptype); };

///<summary>Defines the internal backing store and a json name string</summary>
#define DEFINE_PROPERTY_VARIABLES(propclass, proptype, propname, jsonname) \
	static const Platform::String^ __JSON_PROPERTYNAME( propname ); \
	proptype PROPERTY_VARIABLE( propname ) ;



///<summary>Implements property getter/setter and (json) property name as string within the .cpp file</summary>
#define IMPLEMENT_PROPERTY(propclass, proptype, propname, jsonname) \
const Platform::String^ propclass :: __JSON_PROPERTYNAME( propname ) = jsonname; \
proptype propclass :: propname :: get() { \
	return PROPERTY_VARIABLE( propname ); \
} \
void propclass :: propname:: set(proptype value) { \
	PROPERTY_VARIABLE( propname ) = value; \
}