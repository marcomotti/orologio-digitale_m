import esphome.codegen as cg
import esphome.config_validation as cv

digit_clock_ns = cg.esphome_ns.namespace("digit_clock")
DigitClock = digit_clock_ns.class_("DigitClock", cg.Component)

CONFIG_SCHEMA = cv.Schema({})

async def to_code(config):
    pass

