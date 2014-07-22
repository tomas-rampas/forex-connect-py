#include "stdafx.h"
#include <enums\MessagesColumnsEnum.h>

void export_MessagesColumnsEnum()
{
	using namespace boost::python;

	object obj_MessageColumnsEnum
		= class_<MessageColumnsEnum>("MessageColumnsEnum", "Message columns enumeration", init<>());
	{
		scope in_AccountColumnsEnum(obj_MessageColumnsEnum);
		enum_<MessageColumnsEnum::Columns>("Columns")
			.value("MsgID", MessageColumnsEnum::MsgID)
			.value("Time", MessageColumnsEnum::Time)
			.value("From", MessageColumnsEnum::From)
			.value("Type", MessageColumnsEnum::Type)
			.value("Feature", MessageColumnsEnum::Feature)
			.value("Text", MessageColumnsEnum::Text)
			.value("Subject", MessageColumnsEnum::Subject)
			.value("HTMLFragmentFlag", MessageColumnsEnum::HTMLFragmentFlag)
			.export_values()
			;
	}

	object obj_MessageTableColumnsEnum
		= class_<MessageTableColumnsEnum>("MessageTableColumnsEnum", "Message table columns enumeration", init<>());
	{
		scope in_MessageTableColumnsEnum(obj_MessageTableColumnsEnum);
		enum_<MessageTableColumnsEnum::Columns>("Columns")
			.value("MsgID", MessageTableColumnsEnum::MsgID)
			.value("Time", MessageTableColumnsEnum::Time)
			.value("From", MessageTableColumnsEnum::From)
			.value("Type", MessageTableColumnsEnum::Type)
			.value("Feature", MessageTableColumnsEnum::Feature)
			.value("Text", MessageTableColumnsEnum::Text)
			.value("Subject", MessageTableColumnsEnum::Subject)
			.value("HTMLFragmentFlag", MessageTableColumnsEnum::HTMLFragmentFlag)
			.export_values()
			;
		;
	}
}