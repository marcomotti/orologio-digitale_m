import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import light

digit_clock_ns = cg.esphome_ns.namespace("digit_clock")
DigitClock = digit_clock_ns.class_("DigitClock", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.Required("strip"): cv.use_id(light.AddressableLight)
})

async def to_code(config):
    strip = await cg.get_variable(config["strip"])
    var = cg.new_Pvariable("digitclock", DigitClock(strip))
    await cg.register_component(var, config)
