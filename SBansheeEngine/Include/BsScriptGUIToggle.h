#pragma once

#include "BsScriptEnginePrerequisites.h"
#include "BsScriptObject.h"

namespace BansheeEngine
{
	class BS_SCR_BE_EXPORT ScriptGUIToggle : public ScriptObject<ScriptGUIToggle>
	{
	public:
		static void initMetaData();

		GUIToggle* getInternalValue() const { return mToggle; }
		void* getNativeRaw() const { return mToggle; }

	private:
		static void internal_createInstance(MonoObject* instance, MonoObject* content, 
			MonoObject* toggleGroup, MonoString* style, MonoArray* guiOptions);
		static void internal_destroyInstance(ScriptGUIToggle* nativeInstance);
		static void internal_setContent(ScriptGUIToggle* nativeInstance, MonoObject* content);
		static void internal_toggleOn(ScriptGUIToggle* nativeInstance);
		static void internal_toggleOff(ScriptGUIToggle* nativeInstance);

		static void internal_destroy(ScriptGUIToggle* nativeInstance);
		static void internal_setVisible(ScriptGUIToggle* nativeInstance, bool visible);
		static void internal_setParent(ScriptGUIToggle* nativeInstance, MonoObject* parentLayout);

		static void initRuntimeData();

		static void onClick(MonoObject* instance);
		static void onHover(MonoObject* instance);
		static void onOut(MonoObject* instance);
		static void onToggled(MonoObject* instance, bool toggled);

		ScriptGUIToggle(GUIToggle* toggle);

		void destroy();

		GUIToggle* mToggle;
		bool mIsDestroyed;

		typedef void (__stdcall *OnClickThunkDef) (MonoObject*, MonoException**);
		typedef void (__stdcall *OnHoverThunkDef) (MonoObject*, MonoException**);
		typedef void (__stdcall *OnOutThunkDef) (MonoObject*, MonoException**);
		typedef void (__stdcall *OnToggledThunkDef) (MonoObject*, bool toggled, MonoException**);

		static OnClickThunkDef onClickThunk;
		static OnHoverThunkDef onHoverThunk;
		static OnOutThunkDef onOutThunk;
		static OnToggledThunkDef onToggledThunk;
	};
}