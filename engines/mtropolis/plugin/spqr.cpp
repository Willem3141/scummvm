/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "graphics/managed_surface.h"

#include "mtropolis/plugin/spqr.h"
#include "mtropolis/plugins.h"

#include "mtropolis/miniscript.h"

namespace MTropolis {

namespace SPQR {

FadeModifier::FadeModifier() {
}

FadeModifier::~FadeModifier() {
}

bool FadeModifier::load(const PlugInModifierLoaderContext &context, const Data::SPQR::FadeModifier &data) {
	return true;
}

bool FadeModifier::respondsToEvent(const Event &evt) const {
	return false;
}

VThreadState FadeModifier::consumeMessage(Runtime *runtime, const Common::SharedPtr<MessageProperties> &msg) {
	return kVThreadReturn;
}

void FadeModifier::disable(Runtime *runtime) {
}

#ifdef MTROPOLIS_DEBUG_ENABLE
void FadeModifier::debugInspect(IDebugInspectionReport *report) const {
}
#endif

Common::SharedPtr<Modifier> FadeModifier::shallowClone() const {
	return Common::SharedPtr<Modifier>(new FadeModifier(*this));
}

const char *FadeModifier::getDefaultName() const {
	return "Fade Modifier";	// ???
}

PanningModifier::PanningModifier() {
}

PanningModifier::~PanningModifier() {
}

bool PanningModifier::load(const PlugInModifierLoaderContext &context, const Data::SPQR::PanningModifier &data) {
	return true;
}

bool PanningModifier::respondsToEvent(const Event &evt) const {
	return false;
}

VThreadState PanningModifier::consumeMessage(Runtime *runtime, const Common::SharedPtr<MessageProperties> &msg) {
	return kVThreadReturn;
}

void PanningModifier::disable(Runtime *runtime) {
}

#ifdef MTROPOLIS_DEBUG_ENABLE
void PanningModifier::debugInspect(IDebugInspectionReport *report) const {
}
#endif

Common::SharedPtr<Modifier> PanningModifier::shallowClone() const {
	return Common::SharedPtr<Modifier>(new PanningModifier(*this));
}

const char *PanningModifier::getDefaultName() const {
	return "Panning Modifier";	// ???
}

SPQRPlugIn::SPQRPlugIn()
	: _fadeModifierFactory(this), _panningModifierFactory(this) {
}

void SPQRPlugIn::registerModifiers(IPlugInModifierRegistrar *registrar) const {
	registrar->registerPlugInModifier("fade", &_fadeModifierFactory);
	registrar->registerPlugInModifier("panning", &_panningModifierFactory);
}

} // namespace SPQR

namespace PlugIns {

Common::SharedPtr<PlugIn> createSPQR() {
	return Common::SharedPtr<PlugIn>(new SPQR::SPQRPlugIn());
}

} // End of namespace PlugIns

} // End of namespace MTropolis
